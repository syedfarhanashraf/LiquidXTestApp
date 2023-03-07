// Fill out your copyright notice in the Description page of Project Settings.


#include "DashComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"


// Sets default values for this component's properties
UDashComponent::UDashComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDashComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	MovementComponent = GetOwner()->FindComponentByClass<UCharacterMovementComponent>();
	SetupInput();
	
}


// Called every frame
void UDashComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UDashComponent::SetupInput()
{
	UInputComponent* InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Dashing", IE_Pressed, this, &ThisClass::Dash);
	}
}

void UDashComponent::Dash()
{
	if (!MovementComponent) return;
	
	if (MovementComponent->Velocity != FVector::ZeroVector)
	{
		const FVector ForwardDir = GetOwner()->GetActorRotation().Vector();
		Cast<ACharacter>(GetOwner())->LaunchCharacter(ForwardDir * DashSpeed * DashDistance, true, true);
	}
}

