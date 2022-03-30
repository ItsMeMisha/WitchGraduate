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

	struct ContainsPredicate {
		UItem* compareItem;
		bool operator() (const UItem* item) {
			return *compareItem == *item;
		}
	};

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	int32 size;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	TArray<UItem*> Contents;

	UFUNCTION()
	void Add(UItem& item);

	UFUNCTION()
	void AddUnique(UItem& item);

	UFUNCTION()
	bool Contains(UItem& item);

};
