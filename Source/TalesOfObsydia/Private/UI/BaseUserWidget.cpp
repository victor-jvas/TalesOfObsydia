// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/BaseUserWidget.h"

void UBaseUserWidget::SetWidgetController(UObject* NewWidgetController)
{
	WidgetController = NewWidgetController;
	OnWidgetControllerSet();
}
