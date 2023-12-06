// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/BasePlayerState.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Characters/PlayerCharacter.h"
#include "Player/BasePlayerController.h"

ABasePlayerState::ABasePlayerState()
{
	
	AttributeSet = CreateDefaultSubobject<UBaseAttributeSet>("AttributeSet");
	
	NetUpdateFrequency = 100.f;
}

//return AbilitySystemComponent of the current character;
UAbilitySystemComponent* ABasePlayerState::GetAbilitySystemComponent() const
{
	
	const ABasePlayerController* Controller = Cast<ABasePlayerController>(GetPlayerController());
	APlayerCharacter*  ControlledCharacter = Cast<APlayerCharacter>(Controller->GetCharacter());
	
	return CheckForASC(Cast<const APlayerCharacter>(ControlledCharacter));

}



// Function to get or create an Ability System Component for a character
UAbilitySystemComponent* ABasePlayerState::GetOrCreateASCForCharacter(APlayerCharacter* Character)
{
	UAbilitySystemComponent* ASC = CheckForASC(Character);
	if (ASC)
	{
		return ASC;
	}
	
	//If ASC is nullptr, create a new one for the Character
	ASC = NewObject<UBaseAbilitySystemComponent>(this);
	ASC->RegisterComponent();
	ASC->InitAbilityActorInfo(this, Character);
	AbilitySystemComponents.Add(ASC);
	
	//Add Character to the list of controlled characters so the Controller can switch
	ControlledCharacters.Add(Character);


	return ASC;
}

//Check if the ASC already exist on player and return it, if not return null
UAbilitySystemComponent* ABasePlayerState::CheckForASC(const APlayerCharacter* Character) const
{
	for (UAbilitySystemComponent* ASC : AbilitySystemComponents)
	{
		if (Cast<APlayerCharacter>(ASC->GetAvatarActor()) == Character)
		{
			return ASC;
		}
	}
	return nullptr;
}

bool ABasePlayerState::IsInitialized(APlayerCharacter* PlayerCharacter) const
{
	if(ControlledCharacters.Find(PlayerCharacter) != INDEX_NONE)
	{
		return true;
	}
	return false;
}


void ABasePlayerState::SwitchCharacter()
{
}





