// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetingComponent.generated.h"


class ABaseCharacter;
class AEnemyCharacter;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TALESOFOBSYDIA_API UTargetingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UTargetingComponent();

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadWrite, Category = "Targeting")
	AActor* Target;

public:	

	//UFUNCTION(BlueprintCallable, Category = "Targeting")
	TArray<TObjectPtr<AEnemyCharacter>> GetEnemiesPawns() const;

	
	
	UFUNCTION(BlueprintCallable, Category = "Targeting")
	void SelectTarget();
	void StartTargeting(TArray<TObjectPtr<AEnemyCharacter>> Targets) const;
	
	UFUNCTION(BlueprintCallable, Category = "Targeting")
	AActor* GetTarget() const {return Target;}
};
