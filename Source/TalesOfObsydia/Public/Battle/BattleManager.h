

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleManager.generated.h"


class AEnemyCharacter;
class APlayerCharacter;
class ABaseCharacter;
class ACharacterSpawner;

UCLASS()
class TALESOFOBSYDIA_API ABattleManager : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ABattleManager();

	APlayerController* GetBattleController() const {return BattleController;}

protected:
	
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<APlayerController> BattleController;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TArray<TObjectPtr<ACharacterSpawner>> PartySpawnPoint;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TArray<TObjectPtr<ACharacterSpawner>> EnemySpawnPoint;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configuration|Battle")
	TArray<TObjectPtr<APlayerCharacter>> PlayerParty;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configuration|Battle")
	TArray<TObjectPtr<AEnemyCharacter>> EnemiesParty;
	

	// Pre-Battle
	
	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnCombatants();

	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnPlayerParty();

	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnEnemies();
	

	void BindSpawnEvents();
	
	// Battle
	
	UFUNCTION()
	void AddToCombat(ABaseCharacter* CharacterToAdd);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configuration|Battle")
	TArray<TObjectPtr<ABaseCharacter>> TurnOrder;
	

	

	
	
	
};
