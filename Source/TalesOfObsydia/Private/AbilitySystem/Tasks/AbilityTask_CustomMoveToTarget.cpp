// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTask_CustomMoveToTarget.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"


UAbilityTask_CustomMoveToTarget* UAbilityTask_CustomMoveToTarget::CustomMoveToTarget(UGameplayAbility* OwningAbility)
{
	UAbilityTask_CustomMoveToTarget* MyObj = NewAbilityTask<UAbilityTask_CustomMoveToTarget>(OwningAbility);
	MyObj->bTickingTask = true;
	MyObj->bSimulatedTask = true;
	UE_LOG(LogTemp, Display, TEXT("Entered CreateMoveToTarget"));
	
	return MyObj;
}

void UAbilityTask_CustomMoveToTarget::Activate()
{
	PC = Cast<APlayerCharacter>(Ability->GetAvatarActorFromActorInfo());

	InitialLocation = PC->GetActorTransform();

	AController* PlayerController = Cast<APlayerController>(PC->GetController());

	const AActor* Target = PC->GetTargetedActor();
	
	Destination = Target->GetActorLocation();

	UAIBlueprintHelperLibrary::SimpleMoveToActor(PlayerController,Target);
	
	
}

void UAbilityTask_CustomMoveToTarget::TickTask(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Ticking"));

	
	if (FVector::Dist(PC->GetActorLocation(), Destination) < 150)
	{
		OnTargetReached.Broadcast(PC, InitialLocation);
		//EndTask();
	}
}
