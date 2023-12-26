// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/MoveToTarget_Task.h"

UMoveToTarget_Task* UMoveToTarget_Task::CreateMoveToTarget(UGameplayAbility* OwningAbility)
{
	UMoveToTarget_Task* MyObj = NewAbilityTask<UMoveToTarget_Task>(OwningAbility);
	return MyObj;
}
