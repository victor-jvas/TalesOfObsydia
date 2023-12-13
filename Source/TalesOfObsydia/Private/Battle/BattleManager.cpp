// Fill out your copyright notice in the Description page of Project Settings.


#include "Battle/BattleManager.h"


#include "AbilitySystemComponent.h"
#include "Abilities/Async/AbilityAsync_WaitGameplayTag.h"
#include "AbilitySystem/BaseAttributeSet.h"
#include "Battle/CharacterSpawner.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/EnemyCharacter.h"
#include "Characters/PlayerCharacter.h"
#include "Characters/BaseCharacter.h"
#include "Kismet/GameplayStatics.h"



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

ABaseCharacter* ABattleManager::GetCurrentTurnCharacter()
{
	if (TurnOrder.IsEmpty())
	{
		return nullptr;	
	}

	return TurnOrder[0];
	
}

void ABattleManager::BeginPlay()
{
	Super::BeginPlay();
	BattleController = UGameplayStatics::GetPlayerController(this, 0);

	//BindSpawnEvents();
	SpawnPlayerParty();
	SpawnEnemies();
	
	OnSpawnFinished();

	StartActionBar();
	UE_LOG(LogTemp, Display, TEXT("Arrived Here"));
	
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

void ABattleManager::StartTurn() const
{
	const FInputModeUIOnly UIMode;
	BattleController->SetInputMode(UIMode);

	if (const auto BattleMenu = ShowBattleMenu())
	{
		//BattleMenu->SetUserFocus(BattleController);
		//BattleMenu->SetKeyboardFocus();
		const auto MenuButton = BattleMenu->WidgetTree->FindWidget(FName("BTN_Attack"));
		MenuButton->SetUserFocus(BattleController);
		
	}
	
}

void ABattleManager::AddToTurnOrder(const TObjectPtr<ABaseCharacter> Character)
{
	if (TurnOrder.IsEmpty())
	{
		TurnOrder.Add(Character);
		if (Cast<APlayerCharacter>(Character))
		{
			BattleController->Possess(Character);
			StartTurn();
		}
		//Character->StartTurn();
	}
	else
	{
		TurnOrder.Add(Character);
	}
	
}

int32 ABattleManager::GetElementIndex(APlayerCharacter* PlayerCharacter)
{
	for (int i = 0; i < PlayerParty.Num(); i++)
	{
		if (PlayerCharacter == PlayerParty[0])
		{
			return i;
		}
	}
	return -1;
}

//TODO: Change method type and add return statement
void ABattleManager::GetCharacterStatusWidget()
{
	if (ABaseCharacter* Character = GetCurrentTurnCharacter())
	{
		UWidget* StatusWidget;
		const auto PlayerCharacter = Cast<APlayerCharacter>(Character);

		switch (GetElementIndex(PlayerCharacter))
		{
		case 0:
			StatusWidget = BattleUI->WidgetTree->FindWidget(FName("FirstCharacterStatus"));
			break;
		case 1:
			StatusWidget = BattleUI->WidgetTree->FindWidget(FName("SecondCharacterStatus"));
			break;
		case 2:
			StatusWidget = BattleUI->WidgetTree->FindWidget(FName("ThirdCharacterStatus"));
			break;
		default:
			UE_LOG(LogTemp, Display, TEXT("Character not found in Player Party"));
			break;
		}
	}
}

UUserWidget* ABattleManager::ShowBattleMenu() const
{
	UUserWidget* BattleMenu = Cast<UUserWidget>(BattleUI->WidgetTree->FindWidget(FName("BattleMenu")));

	BattleMenu->SetVisibility(ESlateVisibility::Visible);

	return BattleMenu;
}




