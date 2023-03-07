// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GrabComponent.generated.h"

class UCameraComponent;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GRABFEATURERUNTIME_API UGrabComponent : public UActorComponent
{
	GENERATED_BODY()
private:

	UPROPERTY()
	UCameraComponent* Camera;

	UPROPERTY()
	UPrimitiveComponent* GrabedObject;

	UPROPERTY()
	float FiringForce;

	UPROPERTY()
	float PickUpRadius;

	TSubclassOf<UUserWidget> CrossHairWidgetClass;

	void SetupInput();
	void Grab();
	void Shoot();

	void SaveGeabedObject(UPrimitiveComponent* InGrabPickObject);

public:	
	// Sets default values for this component's properties
	UGrabComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
