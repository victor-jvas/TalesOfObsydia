// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SelectionButtonWidget.h"

#include "Battle/BattleManager.h"
#include "Game/BattleGameMode.h"


// ReSharper disable once CppMemberFunctionMayBeConst
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
	Button->OnHovered.AddDynamic(this, &USelectionButtonWidget::OnHoveredEvent);
	this->OnAddedToFocusPath()

	FFocusEvent* Event;
	Event.
}
