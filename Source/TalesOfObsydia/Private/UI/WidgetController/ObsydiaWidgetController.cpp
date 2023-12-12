// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/ObsydiaWidgetController.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"


void UObsydiaWidgetController::InitController(UBaseAbilitySystemComponent* ASC, APlayerCharacter* Character)
{

	AbilitySystemComponent = ASC;
	PlayerCharacter = Character;
}

void UObsydiaWidgetController::BindCallbacksToDependencies()
{
	const UBaseAttributeSet* AS = AbilitySystemComponent->GetSet<UBaseAttributeSet>();

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetHealthAttribute()).AddUObject(this, &UObsydiaWidgetController::HealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxHealthAttribute()).AddUObject(this, &UObsydiaWidgetController::MaxHealthChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetManaAttribute()).AddUObject(this, &UObsydiaWidgetController::ManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetMaxManaAttribute()).AddUObject(this, &UObsydiaWidgetController::MaxManaChanged);
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AS->GetATBProgressAttribute()).AddUObject(this, &UObsydiaWidgetController::ATBChanged);
}

void UObsydiaWidgetController::HealthChanged(const FOnAttributeChangeData& Data) const
{
	OnHealthChanged.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChanged.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChanged.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChanged.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::ATBChanged(const FOnAttributeChangeData& Data) const
{
	OnATBChanged.Broadcast(Data.NewValue);
}


