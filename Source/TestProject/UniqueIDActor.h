#pragma once

#include "CoreMinimal.h"
#include "StructData.h"
#include "GameFramework/Actor.h"
#include "UniqueIDActor.generated.h"


UCLASS()
class TESTPROJECT_API AUniqueIDActor : public AActor
{
	GENERATED_BODY()

public:

	AUniqueIDActor();

protected:

	virtual void BeginPlay() override;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FActorID ActorData;

	virtual void Tick(float DeltaTime) override;

};
