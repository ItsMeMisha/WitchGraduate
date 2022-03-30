// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InventoryComponent.h"
#include "LockComponent.h"

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Chest.generated.h"

UCLASS()
class WITCHGRADUATE_API AChest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AChest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	ULockComponent* Lock;

	UInventoryComponent* Open(UItem* Unlocker);

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* chestMesh;

	UPROPERTY(VisibleAnywhere)
		UInventoryComponent* Inventory;

	UFUNCTION()
		void OnCursorOverBegin(AActor* TouchedActor);

	UFUNCTION()
		void OnCursorOverEnd(AActor* TouchedActor);
};
