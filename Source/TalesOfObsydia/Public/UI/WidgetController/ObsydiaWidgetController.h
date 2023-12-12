// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/PlayerCharacter.h"
#include "GameFramework/Actor.h"
#include "ObsydiaWidgetController.generated.h"

struct FOnAttributeChangeData;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHealthChangedSignature, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxHealthChangedSignature, float, NewMaxHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnManaChangedSignature, float, NewMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMaxManaChangedSignature, float, NewMaxMana);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnATBChangedSigntaure, float, NewATB);

class APlayerCharacter;
class UBaseAbilitySystemComponent;

UCLASS()
class TALESOFOBSYDIA_API UObsydiaWidgetController : public UObject
{
	GENERATED_BODY()

protected:

	UPROPERTY(BlueprintReadWrite, Category = "Core")
	UBaseAbilitySystemComponent* AbilitySystemComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Core")
	APlayerCharacter* PlayerCharacter;


public:

	UFUNCTION(BlueprintCallable, Category = "Initialization")
	void InitController(UBaseAbilitySystemComponent* ASC, APlayerCharacter* Character);
	
	void BindCallbacksToDependencies();

	void HealthChanged(const FOnAttributeChangeData& Data) const;
	void MaxHealthChanged(const FOnAttributeChangeData& Data) const;
	void ManaChanged(const FOnAttributeChangeData& Data) const;
	void MaxManaChanged(const FOnAttributeChangeData& Data) const;
	void ATBChanged(const FOnAttributeChangeData& Data) const;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnHealthChangedSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxHealthChangedSignature OnMaxHealthChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnManaChangedSignature OnManaChanged;
	UPROPERTY(BlueprintAssignable, Category = "GAS|Attributes")
	FOnMaxManaChangedSignature OnMaxManaChanged;

	UPROPERTY(BlueprintAssignable, Category = "GAS|Battle")
	FOnATBChangedSigntaure OnATBChanged;
	
};
