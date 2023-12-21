// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "TargetListWidget.generated.h"

class UVerticalBox;
class AEnemyCharacter;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UTargetListWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Targeting")
	void SetTargetableEnemies(TArray<AEnemyCharacter*> Targets);


	UFUNCTION(BlueprintCallable, Category = "Targeting")
	void OnTargetSelected(AActor* SelectedTarget);

private:

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* TargetList;
	
};
