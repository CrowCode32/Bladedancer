// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "PaperFlipbookComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "HealthComponent.h"

ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
	
	CharacterSprite = GetSprite();
	if (CharacterSprite)
	{
		CharacterSprite->SetCastShadow(true);
		CharacterSprite->SetUsingAbsoluteRotation(true);
	}

	UHealthComponent* HC = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	CharacterSprite->SetMaterial(0, SpriteMaterial);
}
