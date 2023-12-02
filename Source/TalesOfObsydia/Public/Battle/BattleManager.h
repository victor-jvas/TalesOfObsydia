

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

	

	UFUNCTION(BlueprintCallable, Category = "Pre-Battle")
	virtual void SpawnParty();
	UFUNCTION(BlueprintCallable, Category = "Pre-Battle")
	virtual void SpawnEnemy();
	UFUNCTION(BlueprintCallable, Category = "Pre-Battle")
	virtual void SpawnCombatants();
	

	UFUNCTION()
	void AddToCombat(ABaseCharacter* CharacterToAdd); 
	
	
};
