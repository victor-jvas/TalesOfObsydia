// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


#include "Battle/CharacterSpawner.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"


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
	BattleController = UGameplayStatics::GetPlayerController(this, 0);

	//BindSpawnEvents();
	//SpawnCombatants();
	SpawnPlayerParty();

	
}

void ABattleManager::SpawnCombatants()
{
	checkf(!PartySpawnPoint.IsEmpty(), TEXT("Set the Party Spawn Points in Editor/BP"))
	checkf(!EnemySpawnPoint.IsEmpty(), TEXT("Set the Enemy Spawn Points in Editor/BP"))

	for (const ACharacterSpawner* SpawnPoint : PartySpawnPoint)
	
	{
		
	}

	for (const ACharacterSpawner* SpawnPoint : EnemySpawnPoint)
	
	{
		
	}
}

void ABattleManager::SpawnPlayerParty()
{
	for (const auto SpawnPoint : PartySpawnPoint)
	{
		APlayerCharacter* Char = GetWorld()->SpawnActor<APlayerCharacter>(SpawnPoint->GetClassToSpawn(), SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation());

		if (BattleController)
		{
			BattleController->Possess(Char);
		}
		
	}
}

void ABattleManager::SpawnEnemies()
{
	for (const auto SpawnPoint : EnemySpawnPoint)
	{
		AEnemyCharacter* Enemy = GetWorld()->SpawnActor<AEnemyCharacter>(SpawnPoint->GetClassToSpawn(), SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation());
	}
}

void ABattleManager::AddToCombat(ABaseCharacter* CharacterToAdd)
{
	UE_LOG(LogTemp, Display, TEXT("Character Spawned and Delegate Fired"));

	TurnOrder.Add(CharacterToAdd);
}




