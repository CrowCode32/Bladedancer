// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BasePlayer.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API ABasePlayer : public ABaseCharacter
{
	GENERATED_BODY()
	
public:
	ABasePlayer();

protected:
	virtual void BeginPlay();
};
