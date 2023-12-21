// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TargetListWidget.h"

#include "Blueprint/WidgetTree.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UTargetListWidget::SetTargetableEnemies(TArray<AEnemyCharacter*> Targets)
{

	TargetList = NewObject<UVerticalBox>(GetWorld(), UVerticalBox::StaticClass(), TEXT("TargetList"));
	if (TargetList)
	{
		TargetList->ClearChildren();

		for (auto Target : Targets)
		{
			//UTextBlock* TextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass(), TEXT("TargetTextBlock"));
			UButton* Button = WidgetTree->ConstructWidget<UButton>(UButton::StaticClass(), TEXT("TargetButton"));

			TargetList->AddChild(Button);
		}
	}
	
}

void UTargetListWidget::OnTargetSelected(AActor* SelectedTarget)
{
}
