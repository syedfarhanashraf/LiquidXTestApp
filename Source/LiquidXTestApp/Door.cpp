// Fill out your copyright notice in the Description page of Project Settings.

#include "Door.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ADoor::ADoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	RootComponent = Scene;

	Wall = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Wall"));
	Wall->SetupAttachment(Scene);

	Door = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Door"));
	Door->SetupAttachment(Scene);

	Front = CreateDefaultSubobject<UBoxComponent>(TEXT("Front"));
	Front->SetupAttachment(Scene);
}

// Called when the game starts or when spawned
void ADoor::BeginPlay()
{
	Super::BeginPlay();

	DoorCurrentLocation = Door->GetRelativeLocation();
}

// Called every frame
void ADoor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ADoor::OpenDoor(float ChangeValue)
{
	Door->SetRelativeLocation(FVector(DoorCurrentLocation.X, DoorCurrentLocation.Y, -ChangeValue));
}