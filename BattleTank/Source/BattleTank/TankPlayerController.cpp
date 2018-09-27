// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: Not possessing a tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController: Logging %s as current GetControlledTank"), *(GetControlledTank()->GetName()))
	}
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}