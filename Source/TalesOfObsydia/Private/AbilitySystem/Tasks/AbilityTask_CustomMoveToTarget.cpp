// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilityTask_CustomMoveToTarget.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"


UMoveToTarget_Task* UMoveToTarget_Task::CustomMoveToTarget(UGameplayAbility* OwningAbility)
{
	UMoveToTarget_Task* MyObj = NewAbilityTask<UMoveToTarget_Task>(OwningAbility);
	MyObj->bTickingTask = true;
	MyObj->bSimulatedTask = true;
	UE_LOG(LogTemp, Display, TEXT("Entered CreateMoveToTarget"));
	
	return MyObj;
}

void UMoveToTarget_Task::Activate()
{
	PC = Cast<APlayerCharacter>(Ability->GetAvatarActorFromActorInfo());

	InitialLocation = PC->GetActorLocation();

	APlayerController* PlayerController = Cast<APlayerController>(PC->GetController());

	const AActor* Target = PC->GetTargetedActor();
	
	Destination = Target->GetActorLocation();

	UAIBlueprintHelperLibrary::SimpleMoveToActor(PlayerController,Target);
	
	
}

void UMoveToTarget_Task::TickTask(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Ticking"));

	
	if (FVector::Dist(PC->GetActorLocation(), Destination) < 150)
	{
		OnTargetReached.Broadcast(PC);
		EndTask();
	}
}
