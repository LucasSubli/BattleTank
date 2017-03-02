// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankBarrel.h"


void UTankBarrel::Elevate(float RelativeSpeed) {

	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, 1);

	//remember to make it framerate independent
	auto ElevationChange = RelativeSpeed * MaxDegreesPerSecond * GetWorld()->DeltaTimeSeconds;

	auto NewElevation = FMath::Clamp<float>(RelativeRotation.Pitch + ElevationChange, MinElevationDegree, MaxElevationDegree);

	SetRelativeRotation(FRotator(NewElevation, 0, 0));

}


