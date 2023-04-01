#include "UniqueIDActor.h"

AUniqueIDActor::AUniqueIDActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AUniqueIDActor::BeginPlay()
{
	Super::BeginPlay();
}

void AUniqueIDActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

