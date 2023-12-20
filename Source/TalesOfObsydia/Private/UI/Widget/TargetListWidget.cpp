// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TargetListWidget.h"

#include "UnrealWidgetFwd.h"
#include "Battle/BattleManager.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/BaseCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Button.h"
#include "Components/ListView.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"
#include "UI/Widget/SelectionButtonWidget.h"

void UTargetListWidget::OnTargetButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("Target Button Clicked"));
}


void UTargetListWidget::UpdateTargetList(TArray<AEnemyCharacter*> Targets, AController* Controller)
{
	UListView* TargetList = Cast<UListView>(WidgetTree->FindWidget(FName("TargetList")));
	if (TargetList)
	{
		TargetList->ClearListItems();

		TargetActors.Empty();

		for (const auto Element : Targets)
		{
			
			USelectionButtonWidget* TargetButton = NewObject<USelectionButtonWidget>(this, USelectionButtonWidget::StaticClass());

			APlayerController* PlayerController = Cast<APlayerController>(Controller);
			
			TargetButton->InitializeButton(Element, PlayerController);
			TargetButton->BindEvents();
			TargetActors.Add(Element);
			TargetList->AddItem(TargetButton);

			/*if (TargetButton)
			{
				if (UTextBlock* TextBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass()))
				{
					TextBlock->SetText(FText::FromString(Element->GetName()));
					//TargetButton->OnClicked.AddDynamic(this, &UTargetListWidget::OnTargetButtonClicked);
					//TargetButton->OnHovered.AddDynamic(this, &UTargetListWidget::OnTargetButtonHovered);
					TargetButton->Button->AddChild(TextBlock);
					//TargetList->AddChild(TargetButton);

					TargetList->AddItem(TargetButton);
					
				}
			}*/
		}
	}
}
