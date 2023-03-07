// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Door.generated.h"

UCLASS()
class ADoor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADoor();

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* Wall;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UStaticMeshComponent* Door;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class UBoxComponent* Front;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	class USceneComponent* Scene;
	// Called every frame
	virtual void Tick(float DeltaTime) override;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY()
	FVector DoorCurrentLocation;
public:
	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void OpenDoor(float ChangeValue);
};