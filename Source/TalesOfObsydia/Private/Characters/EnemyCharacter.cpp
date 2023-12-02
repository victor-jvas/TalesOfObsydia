// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/EnemyCharacter.h"


#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Components/SphereComponent.h"



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

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();

	AbilitySystemComponent->InitAbilityActorInfo(this, this);
	AddCharacterAbilities();
	SetDefaultAttributes();
	
	AbilitySystemComponent->AddLooseGameplayTags(DefaultTags);
	
	
	
}
