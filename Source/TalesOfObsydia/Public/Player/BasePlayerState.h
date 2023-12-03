// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameFramework/PlayerState.h"
#include "BasePlayerState.generated.h"

class UBaseAbilitySystemComponent;
class APlayerCharacter;
class UAttributeSet;
class UAbilitySystemComponent;

/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API ABasePlayerState : public APlayerState, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:

	ABasePlayerState();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	

	TObjectPtr<UAttributeSet> GetAttributeSet() const{ return AttributeSet;	}

	UBaseAbilitySystemComponent* GetOrCreateASCForCharacter(APlayerCharacter* Character);

	UBaseAbilitySystemComponent* CheckForASC(const APlayerCharacter* Character) const;



protected:

	
	// Gameplay Ability System
	
	UPROPERTY(VisibleAnywhere, Category = "Gameplay Ability System|Abilities")
	TArray<TObjectPtr<UBaseAbilitySystemComponent>> AbilitySystemComponents;
	
	UPROPERTY(VisibleAnywhere, Category = "Gameplay Ability Sytem|Attributes")
	TObjectPtr<UAttributeSet> AttributeSet;

	// Character Handling

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Gameplay Ability System")
	TArray<TObjectPtr<APlayerCharacter>> ControlledCharacters;

	//TODO: maybe put this in controller?
	UFUNCTION(BlueprintCallable, Category = "Gameplay Ability System")
	void SwitchCharacter();

	
	
};
