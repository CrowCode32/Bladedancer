// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "LevelSequencePlayer.h"
#include "LevelSequence.h"
#include "CutsceneManager.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API UCutsceneManager : public UGameInstanceSubsystem
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable)
	void PlayCutscene(ULevelSequence* Sequence);

	UFUNCTION(BlueprintCallable)
	void PauseCutscene();

	UFUNCTION(BlueprintCallable)
	void ContinueCutscene();

private:
	UPROPERTY()
	ULevelSequencePlayer* SequencePlayer;
	
};
