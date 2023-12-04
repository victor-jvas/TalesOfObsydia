// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/CharacterSpawner.h"

#include "Components/BoxComponent.h"



ACharacterSpawner::ACharacterSpawner()
{
 	RootComponent = CreateDefaultSubobject<USceneComponent>("DefaultSceneRoot");

	SpawnVolume = CreateDefaultSubobject<UBoxComponent>("SpawnVolume");
	SpawnVolume->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

}



