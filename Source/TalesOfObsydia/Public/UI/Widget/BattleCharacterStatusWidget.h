// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Characters/PlayerCharacter.h"
#include "BattleCharacterStatusWidget.generated.h"

class APlayerCharacter;
class UBaseAbilitySystemComponent;
class UTextBlock;
class UEditableText;
class UProgressBar;
/**
 * 
 */

USTRUCT(BlueprintType)
struct FBattleWidgetController
{
	GENERATED_BODY()

	FBattleWidgetController() {};

	TObjectPtr<UBaseAbilitySystemComponent> AbilitySystemComponent;
	
};

UCLASS(BlueprintType)
class TALESOFOBSYDIA_API UBattleCharacterStatusWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeConstruct() override;

	UPROPERTY(BlueprintReadWrite, Category = "Controller")
	TObjectPtr<UBaseAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY(BlueprintReadWrite, Category = "Controller")
	APlayerCharacter* Character;

	UFUNCTION()
	void BindAttributeChangedEvents();
	

public:

	


	UFUNCTION(BlueprintCallable)
	void SetCharacter(APlayerCharacter* InCharacter);

	UFUNCTION(BlueprintImplementableEvent)
	void OnCharacterSet();

	UFUNCTION(BlueprintCallable)
	void InitializeAttributes();
	void SetCharacterInfo(const APlayerCharacter* PlayerCharacter);

	/*UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UProgressBar* HealthBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ManaBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ActiveTimeBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> Name;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthValue;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> ManaValue;*/
};
