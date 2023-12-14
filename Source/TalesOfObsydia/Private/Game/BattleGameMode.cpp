// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BattleGameMode.h"


#include "Battle/BattleManager.h"
#include "Kismet/GameplayStatics.h"


class ABattleCamera;

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));
	//BattleManager->SpawnPlayerParty();

	auto PlayerParty = BattleManager->GetPlayerParty();
	
}

TObjectPtr<ABattleManager> ABattleGameMode::GetBattleManager() const
{
	return BattleManager;
}

