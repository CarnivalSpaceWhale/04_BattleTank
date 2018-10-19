// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	void SetBarrelReference(UStaticMeshComponent* BarrelToSet);

	//TODO Add Set Turret Reference

	void AimAt(FVector AimPoint, float LaunchSpeed);

private:
	UStaticMeshComponent* Barrel = nullptr;

	void MoveBarrelTowards(FVector AimDirection);
};
