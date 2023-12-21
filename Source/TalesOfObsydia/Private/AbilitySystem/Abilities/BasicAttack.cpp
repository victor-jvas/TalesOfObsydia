// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/Abilities/BasicAttack.h"

#include "Abilities/Tasks/AbilityTask_ApplyRootMotionMoveToActorForce.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/Components/TargetingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"


void UBasicAttack::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo,
                                   const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);

	APlayerCharacter* PlayerCharacter = Cast<APlayerCharacter>(ActorInfo->AvatarActor);
	const AEnemyCharacter* TargetEnemy = PlayerCharacter->GetTargetingComponent()->Target;
	
	AController* PlayerController = PlayerCharacter->GetController();
	const UCharacterMovementComponent* MovementComponent = PlayerCharacter->GetCharacterMovement();

	// Set the player character to face the target enemy
	const FRotator TargetRotation = (TargetEnemy->GetActorLocation() - PlayerCharacter->GetActorLocation()).Rotation();
	PlayerCharacter->SetActorRotation(TargetRotation);

	// Move the player character towards the target enemy
	const FVector DirectionToEnemy = (TargetEnemy->GetActorLocation() - PlayerCharacter->GetActorLocation()).GetSafeNormal();
	const FVector MoveVector = DirectionToEnemy * MovementComponent->GetMaxSpeed();
	PlayerCharacter->AddMovementInput(MoveVector);
	
}
