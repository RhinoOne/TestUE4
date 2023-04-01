#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "StructData.generated.h"

class AUniqueIDActor;

UCLASS(BlueprintType)
class TESTPROJECT_API UStructData : public UObject
{
	GENERATED_BODY()

public:

};

USTRUCT(BlueprintType)
struct FActorID
{

	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString NameActor;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString IdActor;

};


USTRUCT(BlueprintType)
struct FActorDataID : public FTableRowBase
{

	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	FString NameActor;	
};


