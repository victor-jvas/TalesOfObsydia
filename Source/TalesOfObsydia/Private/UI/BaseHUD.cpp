// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseHUD.h"

#include "Blueprint/UserWidget.h"
#include "UI/Widget/BaseUserWidget.h"
#include "UI/WidgetController/OverlayWidgetController.h"

UOverlayWidgetController* ABaseHUD::GetOverlayWidgetController(const FWidgetControllerParams& WCParams)
{
	if (WidgetController == nullptr)
	{
		WidgetController = NewObject<UOverlayWidgetController>(this, ControllerClass);
		WidgetController->SetWidgetControllerParams(WCParams);
	}

	return WidgetController;
}

void ABaseHUD::InitOverlay(APlayerController* PC, APlayerState* PS, UAbilitySystemComponent* ASC,
	UAttributeSet* AS) 
{

	checkf(WidgetClass, TEXT("Overlay Class not set, Check BP_BaseHUD"));
	checkf(ControllerClass, TEXT("Controller Class not set, check BP_BaseHUD"));

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), WidgetClass);
	OverlayWidget = Cast<UBaseUserWidget>(Widget);

	const FWidgetControllerParams WCP(PC, PS, ASC, AS);
	UOverlayWidgetController* WController = GetOverlayWidgetController(WCP);

	OverlayWidget->SetWidgetController(WController);
	WidgetController->BroadCastInitialValues();
	WidgetController->BindCallbacksToDependencies();
	
	
	Widget->AddToViewport();
	
	
}

void ABaseHUD::DisplayPlayerTurnHUD()
{
	//TODO: GET Battle Menu and show here
}
