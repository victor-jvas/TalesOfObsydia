// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "Characters/BaseCharacter.h"
#include "AbilityTask_CustomMoveToTarget.generated.h"

class ABaseCharacter;
class APlayerCharacter;
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FTargetReachedSignature, ABaseCharacter*, Character, FTransform, InitialLocation);


/**
 * 
 */
UCLASS()
class UAbilityTask_CustomMoveToTarget : public UAbilityTask
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
	static UAbilityTask_CustomMoveToTarget* CustomMoveToTarget(UGameplayAbility* OwningAbility);
	
	
	


private:

	virtual void Activate() override;

	virtual void TickTask(float DeltaTime) override;
	
	TObjectPtr<APlayerCharacter> PC;
	
	FVector Destination;
	FTransform InitialLocation;
	
};
