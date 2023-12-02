// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


#include "Battle/CharacterSpawner.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"


ABattleManager::ABattleManager()
{
 	
	PrimaryActorTick.bCanEverTick = false;

}

void ABattleManager::BindSpawnEvents()
{
	for (const auto SpawnPoint : PartySpawnPoint)
	{
		SpawnPoint->OnCharacterSpawnedDelegate.AddUniqueDynamic(this, &ABattleManager::AddToCombat);
	}

	for (const auto SpawnPoint : EnemySpawnPoint)
	{
		SpawnPoint->OnCharacterSpawnedDelegate.AddUniqueDynamic(this, &ABattleManager::AddToCombat);
	}
}

void ABattleManager::BeginPlay()
{
	Super::BeginPlay();

	BindSpawnEvents();

	SpawnCombatants();
	BeginCombat();
	
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

void ABattleManager::AddToCombat(ABaseCharacter* CharacterToAdd)
{
	UE_LOG(LogTemp, Display, TEXT("Character Spawned and Delegate Fired"));

	TurnOrder.Add(CharacterToAdd);
}

void ABattleManager::StartTurn(ABaseCharacter* CurrentCharacter)
{
	CurrentCharacter->InitTurn();
}

void ABattleManager::BeginCombat()
{
	for (int32 Position = 0; Position < TurnOrder.Num(); Position++)
	{
		StartTurn(TurnOrder[Position]);	
	}
	
}

