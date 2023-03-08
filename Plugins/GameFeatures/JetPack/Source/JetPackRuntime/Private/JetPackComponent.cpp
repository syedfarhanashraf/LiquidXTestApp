// Fill out your copyright notice in the Description page of Project Settings.


#include "JetPackComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Character.h"

// Sets default values for this component's properties
UJetPackComponent::UJetPackComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UJetPackComponent::BeginPlay()
{
	Super::BeginPlay();
	CharacterMovementComponent = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();
	SetupInput();
	// ...
	
}


// Called every frame
void UJetPackComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (bJetPackActive)
	{
		UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->AddMovementInput(FVector(0.0f, 0.0f, 1.0f), 1.0f, false);
	}
	// ...
}

void UJetPackComponent::SetupInput()
{
	UInputComponent* InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Fly", IE_Pressed, this, &ThisClass::Fly);
		InputComponent->BindAction("Fly", IE_Released, this, &ThisClass::Fall);
	}
}

void UJetPackComponent::Fly()
{
	bJetPackActive = true;
	CharacterMovementComponent->SetMovementMode(EMovementMode::MOVE_Flying, 0);
	CharacterMovementComponent->AirControl = 1;
	UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->bPressedJump = true;
	UGameplayStatics::GetPlayerCharacter(GetWorld(), 0)->Falling();
}

void UJetPackComponent::Fall()
{
	bJetPackActive = false;
	CharacterMovementComponent->SetMovementMode(EMovementMode::MOVE_Falling, 0);
	CharacterMovementComponent->AirControl = 0.2f;
	UGameplayStatics::GetPlayerCharacter(GetWorld(),0)->bPressedJump = false;
}