

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CharacterSpawner.generated.h"

class ABaseCharacter;
class APlayerCharacter;
class AEnemyCharacter;
class UBoxComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCharacterSpawnedSignature, ABaseCharacter*, Character);

UCLASS()
class TALESOFOBSYDIA_API ACharacterSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	
	ACharacterSpawner();

	UFUNCTION(BlueprintCallable)
	TSubclassOf<ABaseCharacter> GetClassToSpawn() const{return ClassToSpawn;}
	
	UFUNCTION(BlueprintCallable)
	void SetClassToSpawn(const TSubclassOf<ABaseCharacter>& CharacterClass){this->ClassToSpawn = ClassToSpawn;}
	
	UPROPERTY(BlueprintCallable)
	FOnCharacterSpawnedSignature OnCharacterSpawnedDelegate;

protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UBoxComponent> SpawnVolume;

	UPROPERTY(EditAnywhere);
	TSubclassOf<ABaseCharacter> ClassToSpawn;

	
};
