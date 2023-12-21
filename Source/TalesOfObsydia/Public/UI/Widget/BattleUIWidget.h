// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BattleUIWidget.generated.h"

/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UBattleUIWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void AddWidgetToViewPort(UUserWidget* WidgetToAdd);
	
};
