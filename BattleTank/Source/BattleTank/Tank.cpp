// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#include "Tank.h"
#include "TankAimingComponent.h"
#include "Engine/World.h"
#include "TankBarrel.h"
#include "Projectile.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimComp = CreateDefaultSubobject<UTankAimingComponent>(TEXT("AimingComponent"));
}

void ATank::SetBarrelReference(UTankBarrel* BarrelToSet)
{
	TankAimComp->SetBarrelReference(BarrelToSet);
	Barrel = BarrelToSet;
}

void ATank::SetTurretReference(UTankTurret* TurretToSet)
{
	TankAimComp->SetTurretReference(TurretToSet);
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector AimPointLocation)
{
	TankAimComp->AimAt(AimPointLocation, LaunchSpeed);
}

void ATank::Fire()
{
	if (!Barrel) { return; }
	// spawn a projectile at the EndOfBarrel socket on Barrel
	GetWorld()->SpawnActor<AProjectile>(
		ProjectileBlueprint,
		Barrel->GetSocketLocation(FName("EndOfBarrel")),
		Barrel->GetSocketRotation(FName("EndOfBarrel")));

	auto time = GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("%f: Fire Event"), time)

}