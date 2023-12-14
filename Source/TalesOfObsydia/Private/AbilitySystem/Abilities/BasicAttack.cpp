// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "GameplayCueNotifyTypes.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "Battle/BattleManager.h"
#include "Game/BattleGameMode.h"
#include "Kismet/GameplayStatics.h"

void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	
	auto BattleManager = Cast<ABattleGameMode>(UGameplayStatics::GetGameMode(GetWorld()))->GetBattleManager();
	
	
	
}
