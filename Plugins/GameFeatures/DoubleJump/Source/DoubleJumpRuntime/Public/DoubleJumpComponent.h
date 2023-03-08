// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DoubleJumpComponent.generated.h"

class UCharacterMovementComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DOUBLEJUMPRUNTIME_API UDoubleJumpComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	bool bCanDoubleJump = true;
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;

	void SetupInput();
	void Jump();
	UFUNCTION()
		void Landed(const FHitResult& Hit);
public:	
	// Sets default values for this component's properties
	UDoubleJumpComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
