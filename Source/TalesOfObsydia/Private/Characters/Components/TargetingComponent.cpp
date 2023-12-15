


#include "Characters/Components/TargetingComponent.h"

#include "Battle/BattleManager.h"
#include "Game/BattleGameMode.h"


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
	return Cast<ABattleGameMode>(GetWorld()->GetAuthGameMode())->GetBattleManager()->GetEnemiesParty();
}



