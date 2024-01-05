// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Tasks/AbilityTask.h"
#include "AbilityTask_CustomMoveToLocation.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE(FDestinationReachedSignature);
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UAbilityTask_CustomMoveToLocation : public UAbilityTask
{
	GENERATED_BODY()

	UPROPERTY(BlueprintAssignable)
	FDestinationReachedSignature OnDestinationReached;

	UFUNCTION(BlueprintCallable, Category ="Ability|Tasks", meta = (DisplayName="Custom Move To Location", HidePin="OwningAbility", DefaultToSelf="OwningAbility", BlueprintInternalUseOnly = "true"))
	static UAbilityTask_CustomMoveToLocation* CustomMoveToLocation(UGameplayAbility* OwningAbility, FVector Destination);

	

	virtual void Activate() override;

	virtual void TickTask(float DeltaTime) override;
	
	TObjectPtr<ACharacter> MovingCharacter;

	FVector Destination;
	
	
};
