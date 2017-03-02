// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS( ClassGroup = (Custom), meta = (BlueprintSpawnableComponent) )
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
	
public:
	// -1 is max downward speed 1 is max upwards speed
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 10.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxElevationDegree = 40.f;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinElevationDegree = 0.f;
	
};
