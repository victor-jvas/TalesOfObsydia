// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class USphereComponent;
class UBaseAbilitySystemComponent;
class UBaseAttributeSet;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AEnemyCharacter();

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> CollisionSphere;
};
