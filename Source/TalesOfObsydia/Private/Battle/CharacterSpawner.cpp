// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/CharacterSpawner.h"


#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Components/BoxComponent.h"
#include "Player/BasePlayerState.h"


ACharacterSpawner::ACharacterSpawner()
{
 	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>("SpawnVolume");
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}

void ACharacterSpawner::SpawnCharacter() const
{
	
	if (PlayerClass)
	{
		SpawnPlayerCharacter();
	}
	else
	{
		SpawnEnemyCharacter();
	}
}


void ACharacterSpawner::SpawnPlayerCharacter() const
{
	const FRotator Rotation = GetActorRotation();
	const FVector Location = GetActorLocation();

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;


	const auto Char = GetWorld()->SpawnActor<APlayerCharacter>(PlayerClass, Location, Rotation, Parameters);
	OnCharacterSpawnedDelegate.Broadcast(Char);

	GetWorld()->GetFirstPlayerController()->Possess(Char);
	
	
}

void ACharacterSpawner::SpawnEnemyCharacter() const
{
	const FRotator Rotation = GetActorRotation();
	const FVector Location = GetActorLocation();

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (UWorld* World = GetWorld())
	{
		const auto Char = World->SpawnActor<AEnemyCharacter>(EnemyClass, Location, Rotation, Parameters);
		OnCharacterSpawnedDelegate.Broadcast(Char);
	}
	
	
}


