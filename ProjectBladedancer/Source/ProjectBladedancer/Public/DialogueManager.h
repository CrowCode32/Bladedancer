// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "MainGameInstance.h"
#include "DialogueWidget.h"
#include "DialogueManager.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FDialogueRow : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int ID;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName Speaker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText Text;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName NextRow;
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDialogueComplete);

UCLASS()
class PROJECTBLADEDANCER_API UDialogueManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintAssignable)
	FDialogueComplete DialogueComplete;

protected:
	UFUNCTION(BlueprintCallable)
	void StartDialogue(FName StartingRowName);

	UFUNCTION(BlueprintCallable)
	void ProgressDialogue();

	UFUNCTION(BlueprintCallable)
	void SkipTyping();

	UFUNCTION(BlueprintCallable)
	bool GetLineComplete();

private:
	void DisplayDialogue(FName RowName);

	UPROPERTY()
	UDialogueWidget* DialogueWidget;

	UPROPERTY()
	UMainGameInstance* Instance;

	FName CurrentRow;
	
};
