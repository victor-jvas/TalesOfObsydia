// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Characters/BaseCharacter.h"
#include "MoveToTarget_Task.generated.h"

class ABaseCharacter;
class APlayerCharacter;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FTargetReachedSignature, ABaseCharacter*, Character);


/**
 * 
 */
UCLASS()
class UMoveToTarget_Task : public UAbilityTask
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "Move To Target" ,HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	static UMoveToTarget_Task* CreateMoveToTarget(UGameplayAbility* OwningAbility);
	
	
	UPROPERTY(BlueprintAssignable)
	FTargetReachedSignature OnTargetReached;

private:

	virtual void Activate() override;

	virtual void TickTask(float DeltaTime) override;

	APlayerCharacter* PC;
	FVector FinalLocation;
	FVector InitialLocation;
};
