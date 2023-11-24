// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/WidgetController/BaseWidgetController.h"
#include "BattleBtnWidgetController.generated.h"

/**
 * 
 */

UCLASS(BlueprintType, Blueprintable)
class TALESOFOBSYDIA_API UBattleBtnWidgetController : public UBaseWidgetController
{
	GENERATED_BODY()

	virtual void BroadCastInitialValues() override;
	virtual void BindCallbacksToDependencies() override;
	
	
};
