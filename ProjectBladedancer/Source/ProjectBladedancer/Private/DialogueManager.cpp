// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueManager.h"
#include "Blueprint/UserWidget.h"
#include "MainGameInstance.h"
#include "DialogueWidget.h"
#include "Engine/DataTable.h"

void UDialogueManager::StartDialogue(FName RowName)
{
	UMainGameInstance* Instance = Cast<UMainGameInstance>(GetGameInstance());
	UDialogueWidget* DialogueWidget = nullptr;
	FDialogueRow* Row = nullptr;
	
	if (Instance){ 
		DialogueWidget = CreateWidget<UDialogueWidget>(GetWorld()->GetFirstPlayerController(), Instance->DialogueWidgetClass); 
		Row = Instance->DialogueData->FindRow<FDialogueRow>(RowName, TEXT("StartDialogue"));
	}
	
	if (DialogueWidget && Row)
	{
		DialogueWidget->SetSpeakerName(Row->Speaker);
		DialogueWidget->SetDialogueText(Row->Text);
		DialogueWidget->SetDialogueIcon(Row->Icon);

		DialogueWidget->AddToViewport();
	}
}
