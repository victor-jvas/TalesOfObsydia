// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "BaseHUD.generated.h"

class UBattleCharacterStatusWidget;
class UBattleBtnWidgetController;
class UAttributeSet;
class UAbilitySystemComponent;
struct FWidgetControllerParams;
class UOverlayWidgetController;
class UBaseUserWidget;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API ABaseHUD : public AHUD
{
	GENERATED_BODY()

public:

	UPROPERTY()
	TObjectPtr<UBaseUserWidget> OverlayWidget;

	UFUNCTION(BlueprintCallable)
	UOverlayWidgetController* GetOverlayWidgetController(const FWidgetControllerParams& WCParams);
	
	void InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC, UAttributeSet* AS);
	void DisplayPlayerTurnHUD();

	void CreateAndInitStatusWidget(TArray<UBattleCharacterStatusWidget*> StatusWidget);

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UBaseUserWidget> WidgetClass;

	UPROPERTY()
	TObjectPtr<UOverlayWidgetController> WidgetController;

	UPROPERTY(EditAnywhere)
	TSubclassOf<UOverlayWidgetController> ControllerClass;
	
};
