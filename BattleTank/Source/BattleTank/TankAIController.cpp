// Fill out your copyright notice in the Description page of Project Settings.

#include "BattleTank.h"
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();

	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("AICOntroller not posssessing a tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("AIController possessing %s"), *(ControlledTank->GetName()));
	}
}



ATank* ATankAIController::GetControlledTank() const {
	return Cast<ATank>(GetPawn());
}