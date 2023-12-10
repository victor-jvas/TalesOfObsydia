// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleCharacterStatusWidget.generated.h"

class UBaseAbilitySystemComponent;
class UTextBlock;
class UEditableText;
class UProgressBar;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UBattleCharacterStatusWidget : public UUserWidget
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBaseAbilitySystemComponent> AbilitySystemComponent;

	UFUNCTION()
	void BindAttributeChangedEvents();
	

public:

	UFUNCTION(BlueprintCallable)
	void InitializeAttributes();

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> HealthBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ManaBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UProgressBar> ActiveTimeBar;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> Name;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> HealthValue;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UTextBlock> ManaValue;
};
