// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
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
	UFUNCTION()
	void OnTargetButtonHovered(UObject* Widget);

	void InitializeButton(UButton* Button, AEnemyCharacter* Element);
	
	UFUNCTION(BlueprintCallable, Category = "TargetList")
	void UpdateTargetList(TArray<AEnemyCharacter*> Targets);
	
private:

	UPROPERTY(VisibleAnywhere, Category = "TargetList")
	TArray<AActor*> TargetActors;
};
