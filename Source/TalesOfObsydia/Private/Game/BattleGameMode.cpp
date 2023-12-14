// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BattleGameMode.h"

#include "EngineUtils.h"
#include "Battle/BattleCamera.h"
#include "Battle/BattleManager.h"
#include "Characters/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Player/BasePlayerController.h"
#include "UI/Widget/BattleCharacterStatusWidget.h"

class ABattleCamera;

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	const ABattleManager* BattleManager = Cast<ABattleManager>(UGameplayStatics::GetActorOfClass(GetWorld(), ABattleManager::StaticClass()));
	//BattleManager->SpawnPlayerParty();

	auto PlayerParty = BattleManager->GetPlayerParty();
	
}

void ABattleGameMode::SetOverviewCamera(ABasePlayerController* PlayerController) const
{
	for (TActorIterator<ABattleCamera> It(GetWorld()); It; ++It)
	{
		if (ABattleCamera* BattleCameraInstance = *It)
		{
			PlayerController->SetViewTargetWithBlend(BattleCameraInstance);
		}
	}
}

void ABattleGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	if (ABasePlayerController* BasePlayerController = Cast<ABasePlayerController>(NewPlayer))
	{
		SetOverviewCamera(BasePlayerController);
	}
}
