// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Item.h"
#include "Containers/Array.h"

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WITCHGRADUATE_API UInventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UInventoryComponent();

	template <class UItemChild>
	struct COntainsPredicate {
		// Predicate that checks if item is concrete child class of Item
		bool operator() (UItem* item) {
			UItemChiled* itemCheck = Cast<UItemChild>(item);
			return itemCheck;
		}
	};

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	int32 size;

	TArray<UItem*> Contents;

	void Add(UItem& item);
	void AddUnique(UItem& item);

	template <class UItemChild>
	bool Contains(UItemChild& item);
};
