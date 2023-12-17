// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SelectionButtonWidget.h"

#include "Battle/BattleManager.h"
#include "Game/BattleGameMode.h"


void USelectionButtonWidget::OnHoveredEvent()
{

	Controller->SetViewTargetWithBlend(ActorRef);
	
}

void USelectionButtonWidget::InitializeButton(AActor* Actor, APlayerController* PlayerController)
{
	ActorRef = Actor;
	Controller = PlayerController;
}

void USelectionButtonWidget::BindEvents()
{
	this->OnHovered.AddDynamic(this, &USelectionButtonWidget::OnHoveredEvent);
}
