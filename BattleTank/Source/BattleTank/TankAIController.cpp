// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTank.h"
#include "TankAimingComponent.h"
#include "Tank.h" // So we can impliment OnDeath
#include "TankAIController.h"



void ATankAIController::BeginPlay() {
	Super::BeginPlay();
}

void ATankAIController::SetPawn(APawn* InPawn) {
	Super::SetPawn(InPawn);
	if (InPawn) {
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) { return; }
		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossedTankDeath);
	}
}

void ATankAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

	auto PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	auto ControlledTank = GetPawn();

	if (!(PlayerTank && ControlledTank)) { return; }

	//Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();

	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked) {
		AimingComponent->Fire();
	}
}

void ATankAIController::OnPossedTankDeath() {
	if (!ensure(GetPawn())) { return; } // TODO remove if ok

	/*auto StaticMesh = GetPawn()->FindComponentByClass<UStaticMeshComponent>();

	TArray<USceneComponent*> Children;

	StaticMesh->GetChildrenComponents(true, Children);

	for (auto* c : Children) {
		c->DestroyComponent();
	}
	StaticMesh->DestroyComponent();*/

	GetPawn()->DetachFromControllerPendingDestroy();

}