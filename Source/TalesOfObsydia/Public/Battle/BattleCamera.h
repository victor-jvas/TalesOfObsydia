// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleCamera.generated.h"

UCLASS()
class TALESOFOBSYDIA_API ABattleCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABattleCamera();

protected:

	virtual void BeginPlay() override;
	

};
