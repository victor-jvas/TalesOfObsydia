


#include "Characters/Components/TargetingComponent.h"

#include "Battle/BattleManager.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Blueprint/WidgetTree.h"
#include "Components/WidgetComponent.h"
#include "Game/BattleGameMode.h"
#include "UI/Widget/BattleUIWidget.h"


UTargetingComponent::UTargetingComponent(): Target(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
	TargetWidget = CreateDefaultSubobject<UWidgetComponent>("Crosshair");
}


void UTargetingComponent::BeginPlay()
{
	Super::BeginPlay();
	
	
}

TArray<TObjectPtr<AEnemyCharacter>> UTargetingComponent::GetEnemiesPawns() const
{
	const ABattleGameMode* GameMode = Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode());
	auto Enemies = GameMode->GetBattleManager()->GetEnemiesParty();
	return Enemies;
}

void UTargetingComponent::SelectTarget()
{
}

void UTargetingComponent::StartTargeting(TArray<TObjectPtr<AEnemyCharacter>> Targets) const
{
	const ABattleGameMode* GameMode = Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode());
	TArray<UUserWidget*> OutWidgets;
	UWidgetBlueprintLibrary::GetAllWidgetsOfClass(GetWorld(), OutWidgets, UBattleUIWidget::StaticClass());
	
		
}



