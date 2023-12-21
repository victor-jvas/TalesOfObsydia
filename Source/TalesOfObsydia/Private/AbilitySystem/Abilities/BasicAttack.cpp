// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "Abilities/Tasks/AbilityTask_MoveToLocation.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"


void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor);
	AController* PlayerController = PlayerCharacter->GetController();
	const auto Target = PlayerCharacter->GetTargetingComponent()->Target;
	const auto TargetLocation = Target->GetActorLocation();

	UAbilityTask_MoveToLocation* MoveToLocationTask = UAbilityTask_MoveToLocation::MoveToLocation(this, FName("MoveToAttack"), TargetLocation, 5.f, nullptr, nullptr);

	
	MoveToLocationTask->ReadyForActivation();

	auto ret = PlayerCharacter->PlayAnimMontage(PlayerCharacter->MovementAnimation);
	
}
