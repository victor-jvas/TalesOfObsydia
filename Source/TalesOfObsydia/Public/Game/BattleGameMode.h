// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Game/DefaultGameMode.h"
#include "Player/BasePlayerController.h"
#include "BattleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API ABattleGameMode : public ADefaultGameMode
{
	GENERATED_BODY()

	virtual void BeginPlay() override;

	//Aux function to set the default camera to be a Overview
	void SetOverviewCamera(ABasePlayerController* PlayerController) const;
	//This is where we set the camera in the beginning
	virtual void PostLogin(APlayerController* NewPlayer) override;
	
};
