// Fill out your copyright notice in the Description page of Project Settings.


#include "ToOAssetManager.h"
#include "AbilitySystemGlobals.h"


void UToOAssetManager::StartInitialLoading()
{
	Super::StartInitialLoading();
	UAbilitySystemGlobals::Get().InitGlobalData();
}
