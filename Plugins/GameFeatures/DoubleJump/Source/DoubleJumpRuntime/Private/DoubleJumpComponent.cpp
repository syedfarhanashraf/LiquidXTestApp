// Fill out your copyright notice in the Description page of Project Settings.


#include "DoubleJumpComponent.h"
#include "Components/InputComponent.h"
#include "EnhancedInputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UDoubleJumpComponent::UDoubleJumpComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDoubleJumpComponent::BeginPlay()
{
	Super::BeginPlay();
	CharacterMovementComponent = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();
	SetupInput();
	// ...
	
}


// Called every frame
void UDoubleJumpComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDoubleJumpComponent::SetupInput()
{
	UInputComponent* InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("DoubleJump", IE_Pressed, this, &ThisClass::Jump);
	}
	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->LandedDelegate.AddDynamic(this, &ThisClass::Landed);
}

void UDoubleJumpComponent::Jump()
{
	if (bCanDoubleJump && CharacterMovementComponent->IsFalling())
	{
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->LaunchCharacter(FVector(0.0f,0.0f,CharacterMovementComponent->JumpZVelocity), false, true);
		bCanDoubleJump = false;
	}
}

void UDoubleJumpComponent::Landed(const FHitResult& Hit)
{
	bCanDoubleJump = true;
}
