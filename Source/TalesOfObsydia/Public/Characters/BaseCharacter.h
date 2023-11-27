// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemInterface.h"
#include "GameplayTagContainer.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

class UGameplayAbility;
class UBaseGameplayAbility;
class UGameplayEffect;
class UAttributeSet;


UCLASS(Abstract)
class TALESOFOBSYDIA_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	UAttributeSet* GetAttributeSet() const{	return AttributeSet; }


protected:
	
	virtual void BeginPlay() override;
	virtual void AddCharacterAbilities();
	virtual void SetDefaultAttributes();

	UPROPERTY(VisibleAnywhere, Category = "GAS|Abilities")
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	
	UPROPERTY(VisibleAnywhere, Category = "GAS|Attributes")
	TObjectPtr<UAttributeSet> AttributeSet;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Abilities")
	TSubclassOf<UGameplayEffect> InitAttributeEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GAS|Abilities")
	TArray<TSubclassOf<UGameplayAbility>> CharacterAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "GAS|Tags")
	FGameplayTagContainer TagContainer;
	
};
