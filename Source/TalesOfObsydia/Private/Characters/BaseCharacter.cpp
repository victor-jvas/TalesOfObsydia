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

	for (const TSubclassOf<UGameplayAbility>& StartupAbility : CharacterAbilities)
	{
		AbilitySystemComponent->GiveAbility(
			FGameplayAbilitySpec(StartupAbility, 1, 1, this));
	}
}

void ABaseCharacter::SetDefaultAttributes()
{
	ApplyEffectToSelf(InitPrimaryAttributesEffect, 1.f);
	ApplyEffectToSelf(InitSecondaryAttributesEffect, 1.f);
	ApplyEffectToSelf(InitVitalAttributesEffect, 1.f);
}

void ABaseCharacter::ApplyEffectToSelf(const TSubclassOf<UGameplayEffect> EffectClass, const float Level)
{
	check(IsValid(GetAbilitySystemComponent()));
	check(EffectClass);
	const FGameplayEffectContextHandle EffectContext = GetAbilitySystemComponent()->MakeEffectContext();
	const FGameplayEffectSpecHandle EffectSpec = GetAbilitySystemComponent()->MakeOutgoingSpec(EffectClass, Level, EffectContext);
	GetAbilitySystemComponent()->ApplyGameplayEffectSpecToTarget(*EffectSpec.Data.Get(), GetAbilitySystemComponent());
}



