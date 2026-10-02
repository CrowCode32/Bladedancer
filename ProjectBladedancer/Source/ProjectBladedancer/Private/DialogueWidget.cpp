// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueWidget.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

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


