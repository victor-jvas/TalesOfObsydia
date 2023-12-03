// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/ToOBaseCharacter.h"

// Sets default values
AToOBaseCharacter::AToOBaseCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AToOBaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AToOBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AToOBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

