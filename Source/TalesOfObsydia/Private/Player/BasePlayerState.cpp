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

//return AbilitySystemComponent;
UAbilitySystemComponent* ABasePlayerState::GetAbilitySystemComponent() const
{
	
	const APlayerCharacter* PC = Cast<APlayerCharacter>(GetInstigatorController()->GetCharacter());
	return CheckForASC(PC);
	return nullptr;
}



// Function to get or create an Ability System Component for a character
UBaseAbilitySystemComponent* ABasePlayerState::GetOrCreateASCForCharacter(APlayerCharacter* Character)
{
	UBaseAbilitySystemComponent* ASC = CheckForASC(Character);
	if (ASC)
	{
		return ASC;
	}
	//If ASC is nullptr, create a new one for the Character
	ASC = NewObject<UBaseAbilitySystemComponent>(this);
	ASC->InitAbilityActorInfo(this, Character);
	AbilitySystemComponents.Add(ASC);


	return ASC;
}

//Check if the ASC already exist on player and return it, if not return null
UBaseAbilitySystemComponent* ABasePlayerState::CheckForASC(const APlayerCharacter* Character) const
{
	for (UBaseAbilitySystemComponent* ASC : AbilitySystemComponents)
	{
		if (Cast<APlayerCharacter>(ASC->GetAvatarActor()) == Character)
		{
			return ASC;
		}
	}
	return nullptr;
}


void ABasePlayerState::SwitchCharacter()
{
}





