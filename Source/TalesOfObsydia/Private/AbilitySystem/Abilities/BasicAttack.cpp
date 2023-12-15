// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "GameplayCueNotifyTypes.h"
#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "Battle/BattleManager.h"
#include "Blueprint/UserWidget.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"
#include "Game/BattleGameMode.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widget/TargetListWidget.h"

void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	
	APlayerCharacter* PC = Cast<APlayerCharacter>(ActorInfo->AvatarActor);

	if (PC)
	{
		//TArray<AEnemyCharacter*> EnemiesPawn = PC->GetTargetingComponent()->GetEnemiesPawns();
		const auto Enemies = PC->GetTargetingComponent()->GetEnemiesPawns();
		const auto TargetListWidget = CreateWidget<UTargetListWidget>(GetWorld(), UTargetListWidget::StaticClass());

		TargetListWidget->AddToViewport();
		TargetListWidget->UpdateTargetList(TArray<ABaseCharacter*>(Enemies));
		
	}
	
	
	
}
