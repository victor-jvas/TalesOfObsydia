// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/ObsydiaWidgetController.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"


void UObsydiaWidgetController::InitController(UBaseAbilitySystemComponent* ASC, APlayerCharacter* Character)
{

	AbilitySystemComponent = ASC;
	PlayerCharacter = Character;
}

void UObsydiaWidgetController::BroadcastInitialValues() const
{
	const UBaseAttributeSet* AS = AbilitySystemComponent->GetSet<UBaseAttributeSet>();
	OnHealthChangedDelegate.Broadcast(AS->GetHealth());
	OnMaxHealthChangedDelegate.Broadcast(AS->GetMaxHealth());
	OnManaChangedDelegate.Broadcast(AS->GetMana());
	OnMaxManaChangedDelegate.Broadcast(AS->GetMaxMana());
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
	OnHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::MaxHealthChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxHealthChangedDelegate.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::ManaChanged(const FOnAttributeChangeData& Data) const
{
	OnManaChangedDelegate.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::MaxManaChanged(const FOnAttributeChangeData& Data) const
{
	OnMaxManaChangedDelegate.Broadcast(Data.NewValue);
}

void UObsydiaWidgetController::ATBChanged(const FOnAttributeChangeData& Data) const
{
	OnATBChangedDelegate.Broadcast(Data.NewValue);
}


