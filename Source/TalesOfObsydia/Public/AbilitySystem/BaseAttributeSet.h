// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "AttributeSet.h"
#include "BaseAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */

UCLASS()
class TALESOFOBSYDIA_API UBaseAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

	

public:

	UBaseAttributeSet();

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

protected:

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

public:


	// Primary Attributes

	UPROPERTY(ReplicatedUsing = OnRep_Speed, BlueprintReadOnly, Category = "Attribute|Primary")
	FGameplayAttributeData Vigor;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Vigor)

	UPROPERTY(ReplicatedUsing = OnRep_Spirit, BlueprintReadOnly, Category = "Attribute|Primary")
	FGameplayAttributeData Spirit;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Spirit)

	UPROPERTY(ReplicatedUsing = OnRep_Agility, BlueprintReadOnly, Category = "Attribute|Primary")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Agility)

	// Secondary Attributes
	
	UPROPERTY(ReplicatedUsing = OnRep_Health, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Health)

	UPROPERTY(ReplicatedUsing = OnRep_MaxHealth, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxHealth)
	
	UPROPERTY(ReplicatedUsing = OnRep_Mana, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Mana)

	UPROPERTY(ReplicatedUsing = OnRep_MaxMana, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, MaxMana)

	UPROPERTY(ReplicatedUsing = OnRep_Speed, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData Speed;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, Speed)

	UPROPERTY(ReplicatedUsing = OnRep_ATBProgress, BlueprintReadOnly, Category = "Attribute|Secondary")
	FGameplayAttributeData ATBProgress;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, ATBProgress)

	// Meta Attributes

	UPROPERTY(BlueprintReadOnly, Category = "Attribute|Meta")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UBaseAttributeSet, IncomingDamage)



	// Replication Notifier Functions
	
	UFUNCTION()
	void OnRep_Vigor(const FGameplayAttributeData& OldVigor) const;
	UFUNCTION()
	void OnRep_Spirit(const FGameplayAttributeData& OldSpirit) const;
	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	UFUNCTION()
	void OnRep_Speed(const FGameplayAttributeData& OldSpeed) const;
	UFUNCTION()
	void OnRep_ATBProgress(const FGameplayAttributeData& OldATBProgress) const;

	
};
