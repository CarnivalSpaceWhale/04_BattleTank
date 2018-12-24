// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Holds Tank Barrel's properties and Elevate method.
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	// -1 is max downward speed, +1 is max upward speed
	void Elevate(float RelativeSpeed);	
	
private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5.f; 

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesElevation = 40.f;

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinDegreesElevation = 0.f;
};
