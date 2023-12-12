

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffect.h"
#include "GameFramework/Actor.h"

#include "BattleManager.generated.h"


class UGameplayEffect;
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

	UFUNCTION(BlueprintImplementableEvent)
	void OnSpawnFinished();
	
	void AddToTurnOrder(TObjectPtr<ABaseCharacter> Object);
	
	virtual void BeginPlay() override;
	
	const float MaxATB = 255;

	// Pre-Battle
	
	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnPlayerParty();

	UFUNCTION(BlueprintCallable, Category = "Configuration|Pre-Battle")
	virtual void SpawnEnemies();

	virtual void StartActionBar();

	void BindSpawnEvents();
	
	// Battle

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Configuration|Battle")
	TArray<TObjectPtr<ABaseCharacter>> TurnOrder;


protected:
	
	// Properties
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

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TSubclassOf<UGameplayEffect> ActionBarEffect;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Configuration|Pre-Battle")
	TSubclassOf<UGameplayEffect> TurnReadyEffect;


	// Getters and Setters
public:
	TArray<TObjectPtr<ABaseCharacter>> GetTurnOrder() const
	{
		return TurnOrder;
	}
	

	TArray<TObjectPtr<APlayerCharacter>> GetPlayerParty() const
	{
		return PlayerParty;
	}

	TArray<TObjectPtr<AEnemyCharacter>> GetEnemiesParty() const
	{
		return EnemiesParty;
	}
	
};
