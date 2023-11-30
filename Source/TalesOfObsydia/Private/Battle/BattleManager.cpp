// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


#include "Battle/CharacterSpawner.h"
#include "Characters/PlayerCharacter.h"


ABattleManager::ABattleManager()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}


void ABattleManager::BeginPlay()
{
	Super::BeginPlay();

	SpawnParty();
	
	
}


void ABattleManager::SpawnParty()
{
	checkf(!PartySpawnPoint.IsEmpty(), TEXT("Set the Spawn Points in Editor/BP"))
	for (const ACharacterSpawner* SpawnPoint : PartySpawnPoint)
	
	{
		SpawnPoint->SpawnEnemyCharacter();
	}
}

void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

