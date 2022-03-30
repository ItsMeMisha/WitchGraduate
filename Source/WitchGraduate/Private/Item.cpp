// Fill out your copyright notice in the Description page of Project Settings.


#include "Item.h"

UItem::UItem() {
	UnlockerType = ELockType::None;
	itemTypeId = GetNextTypeId();
}

UItem::UItem(UItem& copyItem) : UnlockerType(copyItem.UnlockerType), itemTypeId(copyItem.itemTypeId) {}

bool UItem::operator==(const UItem& otherItem) const {
	return this->itemTypeId == otherItem.itemTypeId;
}

uint32 UItem::GetNextTypeId() {
	return nextTypeId++;
}