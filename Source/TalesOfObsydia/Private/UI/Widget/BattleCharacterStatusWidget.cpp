// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/BattleCharacterStatusWidget.h"

#include <string>


#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/PlayerCharacter.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"
#include "UI/WidgetController/ObsydiaWidgetController.h"

void UBattleCharacterStatusWidget::NativeConstruct()
{
	Super::NativeConstruct();
	
	/*if (HealthBar)
	{
		UE_LOG(LogTemp, Display, TEXT("Health bar is valid"));
		
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("Health bar is NULL"));
		HealthBar = WidgetTree->ConstructWidget<UProgressBar>();
		//HealthBar = UWidgetTree::ConstructWidget<UProgressBar>();
	}*/
	
}

void UBattleCharacterStatusWidget::SetCharacter(APlayerCharacter* InCharacter)
{
	Character = InCharacter;
}

void UBattleCharacterStatusWidget::SetAbilitySystemComponent(UBaseAbilitySystemComponent* InASC)
{
	AbilitySystemComponent = InASC;
}

void UBattleCharacterStatusWidget::InitWidget(APlayerCharacter* InCharacter)
{
	SetCharacter(InCharacter);
	const auto ASC = Cast<UBaseAbilitySystemComponent>(InCharacter->GetAbilitySystemComponent());
	SetAbilitySystemComponent(ASC);
	CreateWidgetController();
	OnWidgetControllerSet();
	WidgetController->BroadcastInitialValues();
	SetVisibility(ESlateVisibility::Visible);
}

UObsydiaWidgetController* UBattleCharacterStatusWidget::CreateWidgetController()
{
	if (WidgetController)
	{
		return WidgetController;
	}
	
	WidgetController = NewObject<UObsydiaWidgetController>(this, UObsydiaWidgetController::StaticClass());
	WidgetController->InitController(AbilitySystemComponent, Character);
	WidgetController->BindCallbacksToDependencies();
	return WidgetController;
}

void  UBattleCharacterStatusWidget::InitializeAttributes()
{
	/*const UBaseAttributeSet* AttributeSet = Cast<UBaseAttributeSet>(AbilitySystemComponent->GetSet<UAttributeSet>());

	HealthBar->SetPercent(AttributeSet->GetHealth()/AttributeSet->GetMaxHealth());
	ManaBar->SetPercent(AttributeSet->GetMana()/AttributeSet->GetMaxMana());
	const FText Health = FText::AsNumber(AttributeSet->GetHealth());
	HealthValue->SetText(Health);
	const FText Mana = FText::AsNumber(AttributeSet->GetMana());
	ManaValue->SetText(Mana);*/
	
}

void UBattleCharacterStatusWidget::SetCharacterInfo(const APlayerCharacter* PlayerCharacter)
{
	/*if (PlayerCharacter)
	{
		AbilitySystemComponent = Cast<UBaseAbilitySystemComponent>(PlayerCharacter->GetAbilitySystemComponent());
	}
	const UBaseAttributeSet* AttributeSet = Cast<UBaseAttributeSet>(AbilitySystemComponent->GetSet<UAttributeSet>());

	HealthBar->SetPercent(AttributeSet->GetHealth()/AttributeSet->GetMaxHealth());
	ManaBar->SetPercent(AttributeSet->GetMana()/AttributeSet->GetMaxMana());
	const FText Health = FText::AsNumber(AttributeSet->GetHealth());
	HealthValue->SetText(Health);
	const FText Mana = FText::AsNumber(AttributeSet->GetMana());ManaValue->SetText(Mana);
	*/
	
}

void UBattleCharacterStatusWidget::BindAttributeChangedEvents()
{
	/*
	check(AbilitySystemComponent);

	const UBaseAttributeSet* AttributeSet = Cast<UBaseAttributeSet>(AbilitySystemComponent->GetSet<UAttributeSet>());

	check(AttributeSet);
	
	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetHealthAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
	{
		HealthBar->SetPercent(Data.NewValue/AttributeSet->GetMaxHealth());
	});

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetManaAttribute()).AddLambda(
		[this, AttributeSet](const FOnAttributeChangeData& Data)
	{
		ManaBar->SetPercent(Data.NewValue/AttributeSet->GetMaxMana());
	});
	*/
	
}
