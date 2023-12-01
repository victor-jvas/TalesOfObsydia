

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

class ABaseCharacter;
class APlayerCharacter;
class AEnemyCharacter;
class UBoxComponent;

UCLASS()
class TALESOFOBSYDIA_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACharacterSpawner();

	
	UFUNCTION(BlueprintCallable)
	void SpawnCharacter() const;

	UFUNCTION(BlueprintCallable)
	void SpawnPlayerCharacter() const;
	
	UFUNCTION(BlueprintCallable)
	void SpawnEnemyCharacter() const;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> SpawnVolume;

	UPROPERTY(EditAnywhere)
	TSubclassOf<APlayerCharacter> PlayerClass;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemyCharacter> EnemyClass;
};
