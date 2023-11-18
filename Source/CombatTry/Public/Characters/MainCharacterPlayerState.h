// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "AbilitySystemInterface.h"
#include "MainCharacterPlayerState.generated.h"


/**
 * 
 */
UCLASS()
class COMBATTRY_API AMainCharacterPlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

	AMainCharacterPlayerState();

	

public:
	
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadOnly, Category = "Abilities")
	UAbilitySystemComponent* PlayerASC;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	
};
