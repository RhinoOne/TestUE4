#include "RMManagerID.h"
#include "UniqueIDActor.h"
#include <Kismet/GameplayStatics.h>

URMManagerID* URMManagerID::InstancePtr = nullptr;

URMManagerID::URMManagerID()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> ActorsDT(TEXT("DataTable'/Game/IDSystem/ActorsWithId.ActorsWithId'"));

	if (ActorsDT.Succeeded()) 
	{
		DataTableActorsWithId = ActorsDT.Object;
	}
}

URMManagerID* URMManagerID::GetManagerIdInstance()
{
	if(!IsInit())
	{
		InstancePtr = NewObject<URMManagerID>(URMManagerID::StaticClass());
	}

	return InstancePtr;
}

bool URMManagerID::IsInit()
{
	return InstancePtr != nullptr;
}

void URMManagerID::GetAllActorsID(UWorld* World)
{
	
	check(World);
	UGameplayStatics::GetAllActorsOfClass(World, AUniqueIDActor::StaticClass(), ActorWithID);

}

void URMManagerID::CheckingUniqueIdentifier()
{
	TArray<FString> ArrayId;

	for (AActor* ActorWithId : ActorWithID)
	{
		AUniqueIDActor* CurrentActorWithID = Cast<AUniqueIDActor>(ActorWithId);
		FString Name = CurrentActorWithID->ActorData.NameActor;
		FString Id = CurrentActorWithID->ActorData.IdActor;
		
		IdData.Add(Id, Name);
		IdData.MultiFind(Id, ArrayId);

		FActorDataID DataTableActor;
		DataTableActor.NameActor = Name;

		DataTableActorsWithId->AddRow(FName(Id), DataTableActor);

		if (ArrayId.Num() > 1)
		{
			UE_LOG(LogTemp, Warning, TEXT("The Actor's not unique id %s"), *FString(Name));
			check(0);
		}
		else
		{
			ArrayId.Empty();
		}
	}
}


