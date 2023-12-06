// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "Game/CombatInterface.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


class UGameplayAbility;
class UBaseGameplayAbility;
class UGameplayEffect;
class UAttributeSet;


UCLASS(Abstract)
class TALESOFOBSYDIA_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface, public ICombatInterface
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const{	return AttributeSet; }

	virtual void ApplyEffectToSelf(TSubclassOf<UGameplayEffect> EffectClass, float Level);
	virtual void AddCharacterAbilities();

protected:
	
	virtual void BeginPlay() override;
	virtual void SetDefaultAttributes();
	

	UPROPERTY(VisibleAnywhere, Category = "GAS|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
		
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> CharacterAbilities;
	
	UPROPERTY(VisibleAnywhere, Category = "GAS|Attributes")
	TObjectPtr<UAttributeSet> AttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Attributes")
	TSubclassOf<UGameplayEffect> InitPrimaryAttributesEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Attributes")
	TSubclassOf<UGameplayEffect> InitSecondaryAttributesEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Attributes")
	TSubclassOf<UGameplayEffect> InitVitalAttributesEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Battle")
	TSubclassOf<UGameplayEffect> TurnReadyEffect;

	const int32 MaxATB = 255;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Tags")
	FGameplayTagContainer DefaultTags;

public:
	
	UFUNCTION()
	virtual void InitTurn();

	UFUNCTION()
	void IsTurnReady();

	virtual void StartTurn() const override;
};
