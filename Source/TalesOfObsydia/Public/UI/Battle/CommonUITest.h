// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CommonUserWidget.h"
#include "CommonUITest.generated.h"

class UCommonActivatableWidget;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMenuCreatedDelegate, TSubclassOf<UCommonActivatableWidget>, WClass);

/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UCommonUITest : public UCommonUserWidget
{
	GENERATED_BODY()

	

public:
	UPROPERTY(BlueprintCallable, BlueprintAssignable)
	FOnMenuCreatedDelegate MenuCreatedDelegate;

	UFUNCTION(BlueprintImplementableEvent)
	void PushMenu(TSubclassOf<UCommonActivatableWidget> WidgetClass);
	
};
