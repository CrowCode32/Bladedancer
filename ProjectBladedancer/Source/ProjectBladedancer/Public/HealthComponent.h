// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PROJECTBLADEDANCER_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(EditDefaultsOnly)
	float MaxHealth = 1.0f;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	float CurrentHealth = 1.0f;

public:	
	UFUNCTION()
	void HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser);
	
	UPROPERTY(EditDefaultsOnly)
	float HitCooldown = 1.0f;

	FTimerHandle HitTimer;
};
