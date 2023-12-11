// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/BattleGameMode.h"

#include "Battle/BattleManager.h"
#include "UI/Widget/BattleCharacterStatusWidget.h"

void ABattleGameMode::BeginPlay()
{
	Super::BeginPlay();

	ABattleManager BattleManager;

	BattleManager.SpawnPlayerParty();

	auto PlayerParty = BattleManager.GetPlayerParty();

	for (auto PlayerCharacter : PlayerParty)
	{
		UBattleCharacterStatusWidget* StatusWidget = CreateWidget<UBattleCharacterStatusWidget>(GetWorld(), UBattleCharacterStatusWidget::StaticClass());
		if (StatusWidget)
		{
			StatusWidget->AddToViewport();
			StatusWidget->SetCharacterInfo(PlayerCharacter);
		}
	}
	
	
}
