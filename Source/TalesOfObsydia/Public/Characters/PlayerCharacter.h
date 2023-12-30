// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"

class UTargetingComponent;
class UCameraComponent;
class USpringArmComponent;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

	

public:
	
	APlayerCharacter();
	void InitAbilitySystemInfo();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
	virtual void InitTurn() override;

	UFUNCTION(BlueprintCallable, Category = "Components")
	virtual UTargetingComponent* GetTargetingComponent() {return TargetingComponent;}
	
	virtual AActor* GetTargetedActor() override;
private:

	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent;
	UPROPERTY(EditAnywhere, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComponent;
	UPROPERTY(EditAnywhere, Category = "Components")
	TObjectPtr<UTargetingComponent> TargetingComponent;
};
