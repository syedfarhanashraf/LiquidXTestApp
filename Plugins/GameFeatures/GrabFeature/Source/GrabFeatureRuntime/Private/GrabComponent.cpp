// Fill out your copyright notice in the Description page of Project Settings.


#include "GrabComponent.h"
#include "Camera/CameraComponent.h"
#include "Blueprint/UserWidget.h"

// Sets default values for this component's properties
UGrabComponent::UGrabComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	ConstructorHelpers::FClassFinder<UUserWidget> CrossHair(TEXT("/GrabFeature/CrossHair"));
	if (CrossHair.Succeeded())
	{
		CrossHairWidgetClass = CrossHair.Class;
	}
	// ...
}


// Called when the game starts
void UGrabComponent::BeginPlay()
{
	Super::BeginPlay();
	PickUpRadius = 15000.0f;
	FiringForce = 5000.0f;
	Camera = GetOwner()->FindComponentByClass<UCameraComponent>();
	SetupInput();
	CreateWidget<UUserWidget>(GetWorld(), CrossHairWidgetClass, FName(""))->AddToViewport();
}

void UGrabComponent::SetupInput()
{
	UInputComponent* InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent)
	{
		InputComponent->BindAction("Fire", IE_Pressed, this, &ThisClass::Grab);
		InputComponent->BindAction("Fire", IE_Released, this, &ThisClass::Shoot);
	}
}

// Called every frame
void UGrabComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}


void UGrabComponent::Grab()
{
	if (!Camera) return;
	
	const FCollisionQueryParams QueryParams("PhysicsActor", false, GetOwner());
	const FVector StartTrace = Camera->GetComponentLocation();
	const FVector EndTrace = (Camera->GetForwardVector() * PickUpRadius) + StartTrace;
	FHitResult Hit;
	if (GetWorld()->LineTraceSingleByChannel(Hit, StartTrace, EndTrace, ECC_Visibility, QueryParams))
	{
		if (UPrimitiveComponent* PrimObj = Hit.GetComponent())
		{
			if (PrimObj->IsSimulatingPhysics())
			{
				SaveGeabedObject(PrimObj);
			}
		}
	}
}

void UGrabComponent::Shoot()
{
	if (GrabedObject)
	{
		const FVector ShootVelocity = Camera->GetForwardVector() * FiringForce;

		GrabedObject->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
		GrabedObject->SetSimulatePhysics(true);
		GrabedObject->AddImpulse(ShootVelocity, NAME_None, true);

		SaveGeabedObject(nullptr);
	}
}

void UGrabComponent::SaveGeabedObject(UPrimitiveComponent* InGrabPickObject)
{
	GrabedObject = InGrabPickObject;
	if (GrabedObject)
	{
		GrabedObject->SetSimulatePhysics(false);
		GrabedObject->AttachToComponent(GetOwner()->GetRootComponent(), FAttachmentTransformRules::SnapToTargetNotIncludingScale);
		GrabedObject->SetRelativeLocation(GetOwner()->GetActorUpVector() * 150.0f);
	}
}
