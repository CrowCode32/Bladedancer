// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "MainGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API UMainGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UMainGameInstance();

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UUserWidget> DialogueWidgetClass;

	UPROPERTY(EditDefaultsOnly)
	UDataTable* DialogueData;
	
};
