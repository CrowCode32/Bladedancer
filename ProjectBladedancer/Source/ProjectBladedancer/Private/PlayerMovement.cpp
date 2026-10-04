// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerMovement.h"

UPlayerMovement::UPlayerMovement()
{

}

void UPlayerMovement::BeginPlay()
{
	Super::BeginPlay();

}

void UPlayerMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);


}

void UPlayerMovement::PhysFalling(float deltaTime, int32 Iterations)
{
	if (Velocity.Z > 0.0f) { GravityScale = JumpGravity; }
	else { GravityScale = FallGravity; }

	Super::PhysFalling(deltaTime, Iterations);
}

bool UPlayerMovement::DoJump(bool bReplayingMoves, float DeltaTime)
{
	
	bool bJumped = Super::DoJump(bReplayingMoves, DeltaTime);

	if (bJumped && !Acceleration.IsNearlyZero())
	{
		FVector HorizontalVelocity(GetLastUpdateVelocity().X, GetLastUpdateVelocity().Y, 0.0f);

		if (!HorizontalVelocity.IsNearlyZero())
		{
			float Boost = HorizontalVelocity.Size2D() * JumpBoost;
			float Direction = FMath::Sign(Acceleration.X);

			double Boosted = (Velocity.X * JumpMomentum) + (Direction * Boost * JumpDirectionControl); // JumpMomentum% of old velocity + JumpDirectionControl% of intended direction
			Velocity.X = FMath::Clamp(Boosted, -MaxHorizontalVelocity, MaxHorizontalVelocity);
		}
	}
	return bJumped;
}