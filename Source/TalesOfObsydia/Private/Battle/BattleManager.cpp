// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


#include "AbilitySystemComponent.h"
#include "Abilities/Async/AbilityAsync_WaitGameplayTag.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Battle/CharacterSpawner.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Player/BasePlayerState.h"
#include "UI/BaseHUD.h"


ABattleManager::ABattleManager()
{
 	
	PrimaryActorTick.bCanEverTick = true;
	

}

void ABattleManager::BindSpawnEvents()
{
	for (const auto SpawnPoint : PartySpawnPoint)
	{
		//SpawnPoint->OnCharacterSpawnedDelegate.AddUniqueDynamic(this, &ABattleManager::AddToCombat);
	}

	for (const auto SpawnPoint : EnemySpawnPoint)
	{
		//SpawnPoint->OnCharacterSpawnedDelegate.AddUniqueDynamic(this, &ABattleManager::AddToCombat);
	}
}



void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	BattleController = UGameplayStatics::GetPlayerController(this, 0);

	//BindSpawnEvents();
	SpawnPlayerParty();
	SpawnEnemies();

	StartActionBar();

	ABaseHUD* HUD = Cast<ABaseHUD>(BattleController->GetHUD());
	//HUD->InitOverlay(BattleController, BattleController->GetPlayerState<APlayerState>(), nullptr, )
	
}




void ABattleManager::SpawnPlayerParty()
{
	for (const auto SpawnPoint : PartySpawnPoint)
	{
		APlayerCharacter* Char = GetWorld()->SpawnActor<APlayerCharacter>(SpawnPoint->GetClassToSpawn(), SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation());
		PlayerParty.Add(Char);
		
		if (BattleController)
		{
			BattleController->Possess(Char);
			BattleController->UnPossess();
		}
		
	}
}

void ABattleManager::SpawnEnemies()
{
	for (const auto SpawnPoint : EnemySpawnPoint)
	{
		AEnemyCharacter* Enemy = GetWorld()->SpawnActor<AEnemyCharacter>(SpawnPoint->GetClassToSpawn(), SpawnPoint->GetActorLocation(), SpawnPoint->GetActorRotation());
		EnemiesParty.Add(Enemy);
	}
}

void ABattleManager::StartActionBar()
{
	const auto Player = PlayerParty[0];

	const UBaseAttributeSet* AttributeSet = Cast<UBaseAttributeSet>(Player->GetAttributeSet());
	Player->ApplyEffectToSelf(ActionBarEffect,1);
	
	Player->GetAbilitySystemComponent()->GetGameplayAttributeValueChangeDelegate(AttributeSet->GetATBProgressAttribute()).AddLambda(
		[Player, this](const FOnAttributeChangeData& Data)
		{
			
			if (Data.NewValue > MaxATB)
			{
				UE_LOG(LogTemp, Display, TEXT("ATB is full, ready to act"));
				Player->ApplyEffectToSelf(TurnReadyEffect, 1);
				AddToTurnOrder(Player);
			}
		});
	
}

void ABattleManager::AddToTurnOrder(TObjectPtr<ABaseCharacter> Character)
{
	if (TurnOrder.IsEmpty())
	{
		if (Cast<APlayerCharacter>(Character))
		{
			BattleController->Possess(Character);
		}
		Character->StartTurn();
	}
	else
	{
		TurnOrder.Add(Character);
	}
	
}




