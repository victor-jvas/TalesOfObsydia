// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"

#include "AbilitySystemComponent.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"


ABaseCharacter::ABaseCharacter()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

UAbilitySystemComponent* ABaseCharacter::GetAbilitySystemComponent() const
{
	return  AbilitySystemComponent;
}



void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABaseCharacter::AddCharacterAbilities()
{
	if (!HasAuthority()){ return; }

	CastChecked<UBaseAbilitySystemComponent>(AbilitySystemComponent)->AddCharacterAbilities(InitialAbilities);
}

void ABaseCharacter::SetDefaultAttributes()
{
	const FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle EffectSpec = GetAbilitySystemComponent()->MakeOutgoingSpec(InitAttributeEffect, 1, EffectContext);
	CastChecked<UBaseAbilitySystemComponent>(GetAbilitySystemComponent())->ApplyGameplayEffectToSelf(EffectSpec.Data->Def, 1, EffectContext);
}



