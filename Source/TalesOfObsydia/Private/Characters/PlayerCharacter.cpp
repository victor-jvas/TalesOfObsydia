// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/PlayerCharacter.h"

#include "AbilitySystem/BaseAbilitySystemComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Player/BasePlayerController.h"
#include "Player/BasePlayerState.h"
#include "UI/BaseHUD.h"

APlayerCharacter::APlayerCharacter()
{
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("Camera");
	CameraComponent->SetupAttachment(SpringArmComponent);

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 360.f, 0.f);
}


void APlayerCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Set the owner and avatar for the ASC in the server
	InitAbilitySystemInfo();
}

void APlayerCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	//Set the owner and avatar for the ASC in the client
	InitAbilitySystemInfo();
}

void APlayerCharacter::InitAbilitySystemInfo()
{
	ABasePlayerState* PS = Cast<ABasePlayerState>(GetPlayerState());
	check(PS);
	PS->GetAbilitySystemComponent()->InitAbilityActorInfo(PS, this);
	AbilitySystemComponent = PS->GetAbilitySystemComponent();
	AttributeSet = PS->GetAttributeSet();

	if(ABasePlayerController* NewController = Cast<ABasePlayerController>(GetController()))
	{
		if(ABaseHUD* BaseHUD =  Cast<ABaseHUD>(NewController->GetHUD()))
		{
			BaseHUD->InitOverlay(NewController, PS, AbilitySystemComponent, AttributeSet);			
		}
			
	}
	
}
