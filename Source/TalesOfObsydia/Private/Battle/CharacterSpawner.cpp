// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/CharacterSpawner.h"


#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Components/BoxComponent.h"


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
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	

	
	GetWorld()->SpawnActor<APlayerCharacter>(PlayerClass, Location, Rotation, Parameters);
	
}

void ACharacterSpawner::SpawnEnemyCharacter() const
{
	const FRotator Rotation = GetActorRotation();
	const FVector Location = GetActorLocation();

	FActorSpawnParameters Parameters;
	Parameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if (UWorld* World = GetWorld())
	{
		World->SpawnActor<AEnemyCharacter>(EnemyClass, Location, Rotation, Parameters);	
	}
	else
	{
		UE_LOG(LogTemp, Display, TEXT("GetWorld() return nullptr"));
	}
	
	
}


