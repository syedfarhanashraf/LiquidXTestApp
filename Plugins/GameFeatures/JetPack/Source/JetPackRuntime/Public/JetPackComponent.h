// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "JetPackComponent.generated.h"
class UCharacterMovementComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class JETPACKRUNTIME_API UJetPackComponent : public UActorComponent
{
	GENERATED_BODY()
private:
	bool bJetPackActive = false;
	UPROPERTY()
	UCharacterMovementComponent* CharacterMovementComponent;

	void SetupInput();
	void Fly();
	void Fall();
public:	
	// Sets default values for this component's properties
	UJetPackComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
