// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTask_CustomMoveToLocation.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/PlayerCharacter.h"

UAbilityTask_CustomMoveToLocation* UAbilityTask_CustomMoveToLocation::CustomMoveToLocation(
	UGameplayAbility* OwningAbility, FVector Destination)
{
	UAbilityTask_CustomMoveToLocation* MyObj = NewAbilityTask<UAbilityTask_CustomMoveToLocation>(OwningAbility);

	MyObj->bTickingTask = true;
	MyObj->bSimulatedTask = true;
	MyObj->Destination = Destination;

	return MyObj;
}

void UAbilityTask_CustomMoveToLocation::Activate()
{
	MovingCharacter = Cast<APlayerCharacter>(Ability->GetAvatarActorFromActorInfo());

	AController* Controller = MovingCharacter->GetController();

	UAIBlueprintHelperLibrary::SimpleMoveToLocation(Controller, Destination);
}

void UAbilityTask_CustomMoveToLocation::TickTask(float DeltaTime)
{
	if (FVector::Dist(MovingCharacter->GetActorLocation(), Destination) < 100)
	{
		OnDestinationReached.Broadcast();
		//EndTask();
	}
}



