// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseBossAttack.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/DamageType.h"
#include "HealthComponent.h"

// Sets default values
ABaseBossAttack::ABaseBossAttack()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Sprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("Sprite"));
	RootComponent = Sprite;
	Sprite->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	Sprite->SetNotifyRigidBodyCollision(true);
}

// Called when the game starts or when spawned
void ABaseBossAttack::BeginPlay()
{
	Super::BeginPlay();

	Sprite->OnComponentHit.AddDynamic(this, &ABaseBossAttack::OnHit);
	
}

void ABaseBossAttack::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UHealthComponent* HC = OtherActor->FindComponentByClass<UHealthComponent>();
	if (HC)
	{
		UGameplayStatics::ApplyDamage(OtherActor, DamageAmount, nullptr, this, UDamageType::StaticClass());
	}
}

