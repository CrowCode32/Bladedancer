// Fill out your copyright notice in the Description page of Project Settings.


#include "DialogueManager.h"
#include "Engine/DataTable.h"

void UDialogueManager::StartDialogue(FName StartingRowName)
{
	CurrentRow = StartingRowName;
	
	Instance = Cast<UMainGameInstance>(GetGameInstance());
	
	if (Instance){ DialogueWidget = CreateWidget<UDialogueWidget>(GetWorld()->GetFirstPlayerController(), Instance->DialogueWidgetClass); }
	if (DialogueWidget) { DisplayDialogue(StartingRowName); }
}

void UDialogueManager::DisplayDialogue(FName RowName)
{
	FDialogueRow* Row = Instance->DialogueData->FindRow<FDialogueRow>(RowName, TEXT("DisplayDialogue"));
	
	if (Row)
	{
		DialogueWidget->SetSpeakerName(Row->Speaker);
		DialogueWidget->StartTyping(Row->Text);
		DialogueWidget->SetDialogueIcon(Row->Icon);

		DialogueWidget->AddToViewport();
	}
}

void UDialogueManager::ProgressDialogue()
{
	FDialogueRow* Row = Instance->DialogueData->FindRow<FDialogueRow>(CurrentRow, TEXT("DisplayDialogue"));

	if (Row)
	{
		if (Row->NextRow.IsNone())
		{
			DialogueComplete.Broadcast();
			UE_LOG(LogTemp, Warning, TEXT("DialogueManager Broadcast: %s"), *GetName());
			DialogueWidget->RemoveFromParent();
			return;
		}
	}

	CurrentRow = Row->NextRow;
	DisplayDialogue(CurrentRow);
}

void UDialogueManager::SkipTyping()
{
	if (DialogueWidget) { DialogueWidget->SkipTyping(); }
}

bool UDialogueManager::GetLineComplete()
{
	if (DialogueWidget) { return DialogueWidget->LineComplete; }
	
	return false;
}