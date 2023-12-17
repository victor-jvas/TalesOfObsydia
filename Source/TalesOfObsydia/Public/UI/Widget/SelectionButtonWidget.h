// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "SelectionButtonWidget.generated.h"

class UButton;
class FOnButtonHoverEvent;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API USelectionButtonWidget : public UUserWidget
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, Category = "TargetList")
	AActor* ActorRef;

	UPROPERTY(VisibleAnywhere, Category = "TargetList")
	APlayerController* Controller;

	
	
public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	UButton* Button;

	UFUNCTION()
	void OnHoveredEvent();
	
	void InitializeButton(AActor* Actor, APlayerController* PlayerController);
	
	UFUNCTION()
	void BindEvents();
	
	
};
