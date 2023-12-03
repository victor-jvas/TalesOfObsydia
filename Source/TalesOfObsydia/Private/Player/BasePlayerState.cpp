// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BasePlayerState.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "AbilitySystem/BaseGameplayAbility.h"
#include "Characters/PlayerCharacter.h"

ABasePlayerState::ABasePlayerState()
{
	
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* ABasePlayerState::GetAbilitySystemComponent() const
{
	//return AbilitySystemComponent;
}

void ABasePlayerState::AddCharacterAbilities()
{
}

// Function to get or create an Ability System Component for a character
UBaseAbilitySystemComponent* ABasePlayerState::GetOrCreateASCForCharacter(APlayerCharacter* Character)
{

	//Check if the ASC already exist
	for (UBaseAbilitySystemComponent* ASC : AbilitySystemComponents)
	{
		if (Cast<APlayerCharacter>(ASC->GetAvatarActor()) == Character)
		{
			return ASC;
		}
	}
	//If not, create a new one for the Character
	UBaseAbilitySystemComponent* NewASC = NewObject<UBaseAbilitySystemComponent>(this);
	NewASC->InitAbilityActorInfo(this, Character);
	AbilitySystemComponents.Add(NewASC);


	return nullptr;
}





