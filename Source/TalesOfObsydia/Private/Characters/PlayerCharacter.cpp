// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"

#include "Characters/Components/TargetingComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Player/BasePlayerState.h"


APlayerCharacter::APlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

	TargetingComponent = CreateDefaultSubobject<UTargetingComponent>(TEXT("TargetingComponent"));

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);

	
}


void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	const ABasePlayerState* PS = Cast<ABasePlayerState>(GetPlayerState());
	if(!PS->IsInitialized(this))
	{
		//Set the owner and avatar for the ASC in the server
		InitAbilitySystemInfo();
		AddCharacterAbilities();
	}
	
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	const ABasePlayerState* PS = Cast<ABasePlayerState>(GetPlayerState());
	if(!PS->IsInitialized(this))
	{
		//Set the owner and avatar for the ASC in the server
		InitAbilitySystemInfo();
		AddCharacterAbilities();
	}
	
}


void APlayerCharacter::InitTurn()
{
		
}

AActor* APlayerCharacter::GetTargetedActor()
{
	return TargetingComponent->GetTarget();
	
}

void APlayerCharacter::BasicAttack()
{
	
}

void APlayerCharacter::InitAbilitySystemInfo()
{
	ABasePlayerState* PS = Cast<ABasePlayerState>(UGameplayStatics::GetPlayerState(GetWorld(), 0));
	
	check(PS);
	
	AbilitySystemComponent = PS->GetOrCreateASCForCharacter(this);
	
	AttributeSet = PS->GetAttributeSet();
	

	/*if(ABasePlayerController* NewController = Cast<ABasePlayerController>(GetController()))
	{
		if(ABaseHUD* BaseHUD =  Cast<ABaseHUD>(NewController->GetHUD()))
		{
			BaseHUD->InitOverlay(NewController, PS, AbilitySystemComponent, AttributeSet);
			
		}
	}*/

	SetDefaultAttributes();
	
}
