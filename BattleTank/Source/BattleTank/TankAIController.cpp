// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#include "TankAIController.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank) { return; }
	auto ControlledTank = Cast<ATank>(GetPawn());

	ControlledTank->AimAt(PlayerTank->GetActorLocation());
	ControlledTank->Fire();
}