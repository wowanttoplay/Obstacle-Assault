#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	StartLocation = FVector::ZeroVector;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bIsMoving)
	{
		MovePlatform(DeltaTime);
	}
	if (bIsRotate)
	{
		RotatePlatform(DeltaTime);
	}
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	FVector CurrentLocation = GetActorLocation();
	FVector NewLocation = CurrentLocation + MoveSpeed * DeltaTime;
	SetActorLocation(NewLocation);

	Distance = FVector::Dist(StartLocation, NewLocation);
	if (Distance > MaxDistance)
	{
		SetActorLocation(StartLocation + MoveSpeed.GetSafeNormal() * MaxDistance);
		Distance = 0.0f;
		MoveSpeed = -MoveSpeed;
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	FRotator CurrentRotation = GetActorRotation();
	FRotator DeltaRotation = RotationSpeed * DeltaTime;
	SetActorRotation(CurrentRotation + DeltaRotation);
}
