// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "BaseWidgetController.generated.h"

class APlayerCharacter;
class UBaseAbilitySystemComponent;
class ABaseCharacter;
class UAttributeSet;
class UAbilitySystemComponent;

USTRUCT(BlueprintType)
struct FWidgetControllerParams
{
	GENERATED_BODY()

	FWidgetControllerParams() {}
	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS) :
	PlayerController(PC), PlayerState(PS), AbilitySystemComponent(ASC), AttributeSet(AS){};

	FWidgetControllerParams(APlayerController* PC, APlayerState* PS, TMap<APlayerCharacter*, UBaseAbilitySystemComponent*> ASCMap) :
	PlayerController(PC), PlayerState(PS), CharacterASCMap(ASCMap){};

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerController> PlayerController = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<APlayerState> PlayerState = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UAttributeSet> AttributeSet = nullptr;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TMap<APlayerCharacter*, UBaseAbilitySystemComponent*> CharacterASCMap;
};
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UBaseWidgetController : public UObject
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	void SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams);

	virtual void BroadCastInitialValues();
	virtual void BindCallbacksToDependencies();

protected:

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerState> PlayerState;
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TObjectPtr<APlayerController> PlayerController;
	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	 TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;
	 UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	 TObjectPtr<UAttributeSet> AttributeSet;

	UPROPERTY(BlueprintReadOnly, Category = "WidgetController")
	TMap<APlayerCharacter*, UBaseAbilitySystemComponent*> CharacterASCMap;
};
