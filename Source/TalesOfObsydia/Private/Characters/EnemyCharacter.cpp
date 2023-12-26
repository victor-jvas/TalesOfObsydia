// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"


#include "AIHelpers.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Characters/PlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Tasks/AITask_MoveTo.h"


AEnemyCharacter::AEnemyCharacter()
{

	/** Ability System **/
	AbilitySystemComponent = CreateDefaultSubobject<UBaseAbilitySystemComponent>("AbilitySystemComponent");
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
	/** Ability System **/

	CollisionSphere = CreateDefaultSubobject<USphereComponent>("Collision Sphere");
	CollisionSphere->SetVisibility(true);
	CollisionSphere->SetSphereRadius(50.f);

	
	
}

void AEnemyCharacter::InitTurn()
{
	UE_LOG(LogTemp, Display, TEXT("Entering Enemy Turn"));
	
}

void AEnemyCharacter::BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(OtherActor);

	//PlayerCharacter->GetAbilitySystemComponent()->HandleGameplayEvent()
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	AddCharacterAbilities();
	SetDefaultAttributes();
	
	AbilitySystemComponent->AddLooseGameplayTags(DefaultTags);

	CollisionSphere->OnComponentBeginOverlap.AddDynamic(this, &AEnemyCharacter::BeginOverlap);
	
	
	
}
