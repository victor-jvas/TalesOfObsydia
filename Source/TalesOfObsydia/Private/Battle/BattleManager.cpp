// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


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
	for (UObject* SpawnPoint : PartySpawnPoint)
	{
		const AActor* Point = Cast<AActor>(SpawnPoint);

		FRotator Rotation = Point->GetActorRotation();
		FVector Location = Point->GetActorLocation();

		GetWorld()->SpawnActor<APlayerCharacter>(Location, Rotation);
		
	}
}

void ABattleManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

