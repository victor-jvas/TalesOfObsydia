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

	SpawnCombatants();
	
	
}


void ABattleManager::SpawnParty()
{
	checkf(!PartySpawnPoint.IsEmpty(), TEXT("Set the Spawn Points in Editor/BP"))
	for (const ACharacterSpawner* SpawnPoint : PartySpawnPoint)
	
	{
		SpawnPoint->SpawnPlayerCharacter();
	}
}

void ABattleManager::SpawnEnemy()
{
	checkf(!PartySpawnPoint.IsEmpty(), TEXT("Set the Spawn Points in Editor/BP"))
	for (const ACharacterSpawner* SpawnPoint : PartySpawnPoint)
	
	{
		SpawnPoint->SpawnEnemyCharacter();
	}
}

void ABattleManager::SpawnCombatants()
{
	checkf(!PartySpawnPoint.IsEmpty(), TEXT("Set the Party Spawn Points in Editor/BP"))
	checkf(!EnemySpawnPoint.IsEmpty(), TEXT("Set the Enemy Spawn Points in Editor/BP"))

	for (const ACharacterSpawner* SpawnPoint : PartySpawnPoint)
	
	{
		SpawnPoint->SpawnCharacter();
	}

	for (const ACharacterSpawner* SpawnPoint : EnemySpawnPoint)
	
	{
		SpawnPoint->SpawnCharacter();
	}
}

void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

