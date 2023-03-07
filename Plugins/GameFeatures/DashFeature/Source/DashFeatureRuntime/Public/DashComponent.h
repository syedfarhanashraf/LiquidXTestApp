// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DashComponent.generated.h"

class UCharacterMovementComponent;
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DASHFEATURERUNTIME_API UDashComponent : public UActorComponent
{
	GENERATED_BODY()

private:

	UPROPERTY()
	UCharacterMovementComponent* MovementComponent;
	/** Dash Speed. */
	UPROPERTY()
		float DashSpeed = 10.0f;
	UPROPERTY()
		float DashDistance = 200.0f;

	void SetupInput();
	void Dash();
public:	
	// Sets default values for this component's properties
	UDashComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;


		
};
