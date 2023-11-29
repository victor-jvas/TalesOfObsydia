

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

class UBoxComponent;

UCLASS()
class TALESOFOBSYDIA_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACharacterSpawner();

	void SpawnPlayerCharacter() const;
	void SpawnEnemyCharacter() const;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> SpawnVolume;

};
