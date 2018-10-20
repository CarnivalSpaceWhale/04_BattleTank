// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Holds Tank Barrel's properties and Elevate method.
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float DegreesPerSecond);	
	
private:
	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesPerSecond = 20; 

	UPROPERTY(EditAnywhere, Category = Setup)
	float MaxDegreesElevation = 60;

	UPROPERTY(EditAnywhere, Category = Setup)
	float MinDegreesElevation = -10;
};
