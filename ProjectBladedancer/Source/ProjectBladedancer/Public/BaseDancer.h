// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "BaseDancer.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API ABaseDancer : public ABaseCharacter
{
	GENERATED_BODY()

public:
	ABaseDancer();

protected:
	virtual void BeginPlay();
	
};
