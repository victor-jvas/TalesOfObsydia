// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/WidgetController/BaseWidgetController.h"

void UBaseWidgetController::SetWidgetControllerParams(const FWidgetControllerParams& WidgetControllerParams)
{
	PlayerController = WidgetControllerParams.PlayerController;
	PlayerState = WidgetControllerParams.PlayerState;
	AbilitySystemComponent = WidgetControllerParams.AbilitySystemComponent;
	AttributeSet = WidgetControllerParams.AttributeSet;*/
	CharacterASCMap = WidgetControllerParams.CharacterASCMap;
}

void UBaseWidgetController::BroadCastInitialValues()
{
}

void UBaseWidgetController::BindCallbacksToDependencies()
{
}
