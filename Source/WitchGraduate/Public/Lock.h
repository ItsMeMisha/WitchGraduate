// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LockType.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Lock.generated.h"

/**
 * 
 */
UCLASS()
class WITCHGRADUATE_API ULock : public UObject
{
	GENERATED_BODY()

public:	
	
	UPROPERTY(EditAnywhere)
	ELockType lockType;

	bool TryUnlock(/*UnlockerType*/ELockType Unlocker);

	ULock();
};
