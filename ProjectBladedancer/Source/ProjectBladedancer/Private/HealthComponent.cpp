// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent.h"
#include "TimerManager.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	CurrentHealth = MaxHealth;

	if (AActor* Owner = GetOwner())
	{
		Owner->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::HandleTakeAnyDamage);
	}
	
}

void UHealthComponent::HandleTakeAnyDamage(AActor* DamagedActor, float Damage, const UDamageType* DamageType, AController* InstigatedBy, AActor* DamageCauser)
{
	if (GetWorld()->GetTimerManager().IsTimerActive(HitTimer)) { return; } // Return if hit cooldown still going
	CurrentHealth = FMath::Clamp((CurrentHealth - Damage), 0.0f, MaxHealth); // Deal damage
	HealthChanged.Broadcast();
	GetWorld()->GetTimerManager().SetTimer(HitTimer, HitCooldown, false); // Start hit cooldown again once damage dealt
}

