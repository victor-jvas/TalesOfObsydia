// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"
#include "Tasks/Task.h"


void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor);
	AController* PlayerController = PlayerCharacter->GetController();
	const auto Target = PlayerCharacter->GetTargetingComponent()->Target;
	const auto TargetLocation = Target->GetActorLocation();

	const auto Offset = Target->GetActorForwardVector();

	const FVector Location = TargetLocation + (Offset*200);

	
	UAIBlueprintHelperLibrary::SimpleMoveToLocation(PlayerController, Location);

	FTimerHandle TimerHandler;
	PlayerCharacter->GetWorldTimerManager().SetTimer(TimerHandler,this, &UBasicAttack::OnMoveFinished, 3.f, false);
	
}
void UBasicAttack::OnMoveFinished()
{
	UE_LOG(LogTemp, Warning, TEXT("Finished Moving"));
}