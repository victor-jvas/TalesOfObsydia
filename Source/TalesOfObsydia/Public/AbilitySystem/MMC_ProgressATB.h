// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayModMagnitudeCalculation.h"
#include "MMC_ProgressATB.generated.h"

/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UMMC_ProgressATB : public UGameplayModMagnitudeCalculation
{
	GENERATED_BODY()

public:
	
	UMMC_ProgressATB();

	virtual float CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const override;

private:

	FGameplayEffectAttributeCaptureDefinition SpeedDef;

	
	
};
