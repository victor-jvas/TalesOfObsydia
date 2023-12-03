// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ObsydiaGameInstance.generated.h"

class APlayerCharacter;
/**
 * 
 */
UCLASS()
class TALESOFOBSYDIA_API UObsydiaGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	TArray<APlayerCharacter*> GetParty() {return PlayerParty;}
	UFUNCTION(BlueprintCallable)
	void AddCharacterToParty(APlayerCharacter* Character) {PlayerParty.Add(Character);}
	
private:

	UPROPERTY(EditAnywhere)
	TArray<TObjectPtr<APlayerCharacter>> PlayerParty;

	
};
