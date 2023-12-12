// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BattleGameMode.h"

#include "Battle/BattleManager.h"
#include "Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UI/Widget/BattleCharacterStatusWidget.h"

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	const ABattleManager* BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));

	//BattleManager->SpawnPlayerParty();

	auto PlayerParty = BattleManager->GetPlayerParty();
	
	
}
