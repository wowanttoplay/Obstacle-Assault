// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class UNREALLEARNINGKIT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	FVector StartLocation; // 平台初始位置

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform")
	float Distance; // 平台移动的距离

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Platform")
	bool bIsMoving = true; // 是否允许平台移动

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	FVector MoveSpeed; // 平台移动的速度

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	float MaxDistance = 1000.0f; // 最大移动距离，可在蓝图中设置

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	bool bIsRotate = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform")
	FRotator RotationSpeed = FRotator(0.0f, 60.0f, 0.0f); // 平台旋转速度


private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
};

