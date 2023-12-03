

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleManager.generated.h"


class ABaseCharacter;
class ACharacterSpawner;

UCLASS()
class TALESOFOBSYDIA_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABattleManager();

protected:
	
	
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TArray<TObjectPtr<ACharacterSpawner>> PartySpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TArray<TObjectPtr<ACharacterSpawner>> EnemySpawnPoint;

	// Pre-Battle
	
	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnCombatants();

	void BindSpawnEvents();
	
	// Battle
	
	UFUNCTION()
	void AddToCombat(ABaseCharacter* CharacterToAdd);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configuration|Battle")
	TArray<TObjectPtr<ABaseCharacter>> TurnOrder;

	UFUNCTION()
	void StartTurn(ABaseCharacter* CurrentCharacter);
	UFUNCTION()
	void BeginCombat();
	

	

	
	
	
};
