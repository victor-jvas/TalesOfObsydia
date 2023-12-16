


#include "Characters/Components/TargetingComponent.h"

#include "Battle/BattleManager.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Characters/PlayerCharacter.h"
#include "Game/BattleGameMode.h"
#include "GameFramework/GameSession.h"
#include "UI/Widget/TargetListWidget.h"


UTargetingComponent::UTargetingComponent()
{

	PrimaryComponentTick.bCanEverTick = true;


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
	const ABattleGameMode* GM = Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode());
	const UUserWidget* BattleUI = GM->GetBattleManager()->GetBattleUI();

	const auto TargetList = Cast<UTargetListWidget>(BattleUI->WidgetTree->FindWidget(FName("TargetListMenu")));
	TargetList->SetVisibility(ESlateVisibility::Visible);
	
	TargetList->UpdateTargetList(Targets);
	TargetList->SetUserFocus(GM->GetBattleManager()->GetBattleController());
	
}



