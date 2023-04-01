#pragma once
#include "Engine/DataTable.h"
#include "CoreMinimal.h"
#include "RMManagerID.generated.h"

class AUniqueIDActor;

UCLASS()
class TESTPROJECT_API URMManagerID : public UObject
{
	GENERATED_BODY()
	
public:

	URMManagerID();

public:

	static URMManagerID* GetManagerIdInstance();
	static bool IsInit();

	void GetAllActorsID(UWorld* World);
	void CheckingUniqueIdentifier();
	
private:
	
	static URMManagerID* InstancePtr;

	TArray<AActor*> ActorWithID{};

	TMultiMap<FString, FString> IdData;

	UDataTable* DataTableActorsWithId;
};
