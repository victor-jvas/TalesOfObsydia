// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"


void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	
	APlayerCharacter* PC = Cast<APlayerCharacter>(ActorInfo->AvatarActor);

	if (PC)
	{
		const auto Enemies = PC->GetTargetingComponent()->GetEnemiesPawns();
		PC->GetTargetingComponent()->StartTargeting(Enemies);
	}
}
