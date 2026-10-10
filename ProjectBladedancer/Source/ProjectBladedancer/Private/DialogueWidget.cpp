// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "TimerManager.h"

void UDialogueWidget::SetSpeakerName(FName NewSpeakerName)
{
	SpeakerName->SetText(FText::FromName(NewSpeakerName));
}

void UDialogueWidget::SetDialogueText(FText NewDialogueText)
{
	DialogueText->SetText(NewDialogueText);
}

void UDialogueWidget::SetDialogueIcon(UTexture2D* NewDialogueIcon)
{
	DialogueIcon->SetBrushFromTexture(NewDialogueIcon, true);
}

void UDialogueWidget::StartTyping(FText NewDialogueText)
{
	FullText = NewDialogueText;
	FullTextString = NewDialogueText.ToString();
	CurrentIndex = 0;
	DialogueText->SetText(FText::GetEmpty());
	LineComplete = false;

	GetWorld()->GetTimerManager().SetTimer(TypingTimer, this, &UDialogueWidget::TypeNextChar, TypeDelay, false);
}

void UDialogueWidget::TypeNextChar()
{
	++CurrentIndex;
	DialogueText->SetText(FText::FromString(FullTextString.Left(CurrentIndex)));

	if (CurrentIndex >= FullTextString.Len())
	{
		GetWorld()->GetTimerManager().ClearTimer(TypingTimer);
		LineComplete = true;
		return;
	}

	float Delay = TypeDelay;

	// Pause at end of sentences before continuing
	switch (TCHAR(FullTextString[CurrentIndex - 1])) {
	case TEXT('.'):
	case TEXT('?'):
	case TEXT('!'):
		Delay = 0.3f;
	}

	GetWorld()->GetTimerManager().SetTimer(TypingTimer, this, &UDialogueWidget::TypeNextChar, Delay, false);
}

void UDialogueWidget::SkipTyping()
{
	DialogueText->SetText(FullText);
	GetWorld()->GetTimerManager().ClearTimer(TypingTimer);
	LineComplete = true;
}
