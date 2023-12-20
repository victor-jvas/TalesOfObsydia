// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/SelectionButtonWidget.h"

#include "Components/ListView.h"
#include "Components/ListViewBase.h"
#include "Components/TextBlock.h"


// ReSharper disable once CppMemberFunctionMayBeConst
void USelectionButtonWidget::OnHoveredEvent()
{

	Controller->SetViewTargetWithBlend(ActorRef);
	
}

void USelectionButtonWidget::InitializeButton(AActor* Actor, APlayerController* PlayerController)
{
	Button = NewObject<UButton>(this, UButton::StaticClass());
	TextBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
	
	TextBlock->SetText(FText::FromString(Actor->GetName()));
	TextBlock->SetVisibility(ESlateVisibility::Visible);
	

	Cast<UListView>(GetOwningListView())->OnEntryWidgetGenerated();

	Button->SetContent(TextBlock);
	
	ActorRef = Actor;
	Controller = PlayerController;
	
}

void USelectionButtonWidget::BindEvents()
{
	if (Button)
	{
		Button->OnHovered.AddDynamic(this, &USelectionButtonWidget::OnHoveredEvent);
		UE_LOG(LogTemp, Display, TEXT("Button is NOT NULL"));
	}
	
}


