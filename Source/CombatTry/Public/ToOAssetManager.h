// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"
#include "ToOAssetManager.generated.h"

/**
 * 
 */
UCLASS()
class COMBATTRY_API UToOAssetManager : public UAssetManager
{
	GENERATED_BODY()

public:
	
	virtual void StartInitialLoading() override;
	
};
