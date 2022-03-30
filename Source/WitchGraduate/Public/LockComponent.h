// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LockType.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "LockComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class WITCHGRADUATE_API ULockComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULockComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere)
	ELockType lockType;

	bool TryUnlock(/*UnlockerType*/ELockType Unlocker);

};
