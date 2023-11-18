// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MainCharacterPlayerState.h"

#include "AbilitySystemComponent.h"

AMainCharacterPlayerState::AMainCharacterPlayerState()
{
	PlayerASC = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystemComponent"));
	PlayerASC->SetIsReplicated(true);
}

UAbilitySystemComponent* AMainCharacterPlayerState::GetAbilitySystemComponent() const
{
	return PlayerASC;
}
