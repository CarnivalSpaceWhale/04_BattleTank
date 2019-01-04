// CarnivalSpaceWhale Very Definitely Original Code Do Not Steal

#include "TankTrack.h"

void UTankTrack::SetThrottle(float Throttle)
{
	UE_LOG(LogTemp, Warning, TEXT("%s Throttle: %f"), *this->GetName(), Throttle)

	// todo clamp throttle value so input can't exceed +1/-1
}



