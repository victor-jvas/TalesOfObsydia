// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Characters/BaseCharacter.h"
#include "AbilityTask_CustomMoveToTarget.generated.h"

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

	UPROPERTY(BlueprintAssignable)
	FTargetReachedSignature OnTargetReached;

public:

	/**
	 *Move the character to a previously selected target
	 */ 
	UFUNCTION(BlueprintCallable, Category = "Ability|Tasks", meta = (DisplayName = "Custom Move To Target" ,HidePin = "OwningAbility", DefaultToSelf = "OwningAbility", BlueprintInternalUseOnly = "true"))
	// ReSharper disable once CppUEBlueprintCallableFunctionUnused
	static UMoveToTarget_Task* CustomMoveToTarget(UGameplayAbility* OwningAbility);
	
	
	


private:

	virtual void Activate() override;

	virtual void TickTask(float DeltaTime) override;


	UPROPERTY()
	APlayerCharacter* PC;
	
	FVector Destination;
	FVector InitialLocation;
	
};
