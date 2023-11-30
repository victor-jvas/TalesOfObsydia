

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

class AEnemyCharacter;
class UBoxComponent;

UCLASS()
class TALESOFOBSYDIA_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACharacterSpawner();

	UFUNCTION()
	void SpawnPlayerCharacter() const;
	
	UFUNCTION(BlueprintCallable)
	void SpawnEnemyCharacter() const;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> SpawnVolume;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AEnemyCharacter> Enemy;

};
