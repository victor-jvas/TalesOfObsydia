// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "MoveToTarget_Task.generated.h"

/**
 * 
 */
UCLASS()
class UMoveToTarget_Task : public UAbilityTask
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "MoveToTarget" ,HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UMoveToTarget_Task* CreateMoveToTarget(UGameplayAbility* OwningAbility);
};
