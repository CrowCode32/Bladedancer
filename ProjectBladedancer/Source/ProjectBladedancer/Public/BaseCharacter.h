// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "HealthComponent.h"
#include "BaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API ABaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	ABaseCharacter();

protected:
	virtual void BeginPlay();

	UPROPERTY()
	UPaperFlipbookComponent* CharacterSprite;

	UPROPERTY(EditDefaultsOnly)
	UMaterialInstance* SpriteMaterial;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<UActorComponent> HealthComponentClass;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UHealthComponent* HC;
	
};
