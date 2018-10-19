// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#include "TankPlayerController.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"

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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimAtCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimAtCrosshair()
{
	if (!GetControlledTank()) { return; }

	AimPointLocation = FVector(0);
	FString ObjectHit = "Nothing";

	GetCrosshairTraceHit(ObjectHit, AimPointLocation);
	GetControlledTank()->AimAt(AimPointLocation);
}

bool ATankPlayerController::GetCrosshairTraceHit(FString &ObjectHit, FVector &HitLoc) const
{
	// Viewport Size
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	bool bHit;
	FVector2D CrosshairPosition = FVector2D(ViewportSizeX / 2, ViewportSizeY / 3);
	FHitResult HitResult;

	bHit = GetHitResultAtScreenPosition(CrosshairPosition, ECollisionChannel::ECC_Visibility, false, HitResult);

	if (bHit)
	{
		HitLoc = HitResult.ImpactPoint;
		ObjectHit = HitResult.GetActor()->GetName();
	}

	return bHit;
}