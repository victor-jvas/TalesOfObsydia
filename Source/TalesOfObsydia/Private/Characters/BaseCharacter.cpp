// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/BaseCharacter.h"


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



