// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MoveToTarget_Task.h"

#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"



UMoveToTarget_Task* UMoveToTarget_Task::CreateMoveToTarget(UGameplayAbility* OwningAbility)
{
	UMoveToTarget_Task* MyObj = NewAbilityTask<UMoveToTarget_Task>(OwningAbility);
	MyObj->bTickingTask = true;
	MyObj->bSimulatedTask = true;
	return MyObj;
}

void UMoveToTarget_Task::Activate()
{
	PC = Cast<APlayerCharacter>(Ability->GetAvatarActorFromActorInfo());

	APlayerController* PlayerController = Cast<APlayerController>(PC->GetController());

	const AEnemyCharacter* Target = PC->GetTargetingComponent()->GetTarget();

	FinalLocation = Target->GetActorLocation();

	UAIBlueprintHelperLibrary::SimpleMoveToActor(PlayerController, Target);
	
}

void UMoveToTarget_Task::TickTask(float DeltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Ticking"));

	
	if (FVector::Dist(PC->GetActorLocation(), FinalLocation) < 100)
	{
		OnTargetReached.Broadcast();
		EndTask();
		
	}
}
