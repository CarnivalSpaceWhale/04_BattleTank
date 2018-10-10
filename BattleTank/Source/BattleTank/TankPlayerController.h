// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CollisionQueryParams.h"
#include "Engine/World.h"
#include "Tank.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	
	// Points to the tank currently controlled by this PlayerController
	ATank* GetControlledTank() const;

	// Start moving the tank's barrel into position so that a shot fired from the barrel 
	//  will hit the point where the crosshair intersects with the world. 
	void AimAtCrosshair();

	// True if crosshair's "sight ray" hits valid terrain.
	bool GetCrosshairTraceHit(FString &ObjectHit, FVector &HitLoc) const;

	FVector AimPointLocation;
};
