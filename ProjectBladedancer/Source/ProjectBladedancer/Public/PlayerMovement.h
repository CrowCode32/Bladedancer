// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "BasePlayer.h"
#include "PlayerMovement.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTBLADEDANCER_API UPlayerMovement : public UCharacterMovementComponent
{
	GENERATED_BODY()

	UPlayerMovement();

	UPROPERTY(EditDefaultsOnly)
	float FallGravity = 1.0f;

	UPROPERTY(EditDefaultsOnly)
	float MaxHorizontalVelocity = 800.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpGravity = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpBoost = 1.0f;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpMomentum = 0.25;

	UPROPERTY(EditDefaultsOnly, Category = "Jump")
	float JumpDirectionControl = 0.75;

protected:
	virtual void BeginPlay();

	virtual void TickComponent(float DeltaTime, enum ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	virtual void PhysFalling(float deltaTime, int32 Iterations) override;

	virtual bool DoJump(bool bReplayingMoves, float DeltaTime) override;
};
