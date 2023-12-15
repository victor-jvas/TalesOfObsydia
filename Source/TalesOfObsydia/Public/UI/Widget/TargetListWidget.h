// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TargetListWidget.generated.h"

class AEnemyCharacter;
class UVerticalBox;
class ABaseCharacter;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UTargetListWidget : public UUserWidget
{
	GENERATED_BODY()

public:
	UFUNCTION()
	void OnTargetButtonClicked();
	UFUNCTION(BlueprintCallable, Category = "TargetList")
	void UpdateTargetList(TArray<AEnemyCharacter*> Targets);
};
