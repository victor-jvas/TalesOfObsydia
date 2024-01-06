// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/BaseCharacter.h"
#include "EnemyCharacter.generated.h"

class UTargetingComponent;
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

	virtual void InitTurn() override;

protected:
	UFUNCTION()
	void BeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	
	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UTargetingComponent> TargetingComponent;

	UPROPERTY(EditAnywhere)
	TObjectPtr<USphereComponent> CollisionSphere;
};
