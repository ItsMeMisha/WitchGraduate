// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Lock.h"

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Item.generated.h"

/**
 * 
 */
UCLASS()
class WITCHGRADUATE_API UItem : public UObject
{
    GENERATED_BODY()
public:
    ELockType UnlockerType;

    UPROPERTY(VisibleAnywhere)
    uint32 itemTypeId;
    
};
