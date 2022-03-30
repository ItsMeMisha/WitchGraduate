// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "LockType.h"

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
    UPROPERTY(VisibleAnywhere)
    ELockType UnlockerType;

protected:
    UItem(); //Use only for creating one original item

    UPROPERTY(VisibleAnywhere)
    uint32 itemTypeId;

    static uint32 GetNextTypeId();

public:
    static uint32 nextTypeId;
    UItem(UItem& copyItem);

    UFUNCTION()
    uint32 GetTypeId() { return itemTypeId; };

    bool operator==(const UItem& otherItem) const;
    
};

uint32 UItem::nextTypeId = uint32(0);
