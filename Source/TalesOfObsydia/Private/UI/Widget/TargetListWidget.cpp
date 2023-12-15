// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Widget/TargetListWidget.h"

#include "UnrealWidgetFwd.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/BaseCharacter.h"
#include "Characters/EnemyCharacter.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/VerticalBox.h"

void UTargetListWidget::OnTargetButtonClicked()
{
	UE_LOG(LogTemp, Display, TEXT("Target Button Clicked"));
}

void UTargetListWidget::UpdateTargetList(TArray<AEnemyCharacter*> Targets)
{
	UVerticalBox* TargetList = Cast<UVerticalBox>(WidgetTree->FindWidget(FName("TargetList")));

	if (TargetList)
	{
		TargetList->ClearChildren();

		for (auto Element : Targets)
		{
			UButton* TargetButton = NewObject<UButton>(this, UButton::StaticClass());

			if (TargetButton)
			{
				UTextBlock* TextBlock = NewObject<UTextBlock>(this, UTextBlock::StaticClass());
				if (TextBlock)
				{
					TextBlock->SetText(FText::FromString(Element->GetName()));
					TargetButton->OnClicked.AddDynamic(this, &UTargetListWidget::OnTargetButtonClicked);
					TargetButton->AddChild(TextBlock);
					TargetList->AddChild(TargetButton);
				}
			}
		}
	}
}
