// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MMC_ProgressATB.h"

#include "AbilitySystem/BaseAttributeSet.h"

UMMC_ProgressATB::UMMC_ProgressATB()
{
	SpeedDef.AttributeToCapture = UBaseAttributeSet::GetSpeedAttribute();
	SpeedDef.AttributeSource = EGameplayEffectAttributeCaptureSource::Target;
	SpeedDef.bSnapshot = false;

	RelevantAttributesToCapture.Add(SpeedDef);
}

float UMMC_ProgressATB::CalculateBaseMagnitude_Implementation(const FGameplayEffectSpec& Spec) const
{
	const FAggregatorEvaluateParameters EvaluateParameters;

	float Speed = 0.f;
	GetCapturedAttributeMagnitude(SpeedDef, Spec, EvaluateParameters, Speed);

	const auto DeltaTime = Spec.GetEffectContext().GetInstigator()->GetWorld()->GetDeltaSeconds();
	return Speed*DeltaTime;
	
}
