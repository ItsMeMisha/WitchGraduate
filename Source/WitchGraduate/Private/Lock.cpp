// Fill out your copyright notice in the Description page of Project Settings.


#include "Lock.h"

ULock::ULock() {
	lockType = ELockType::None;
}

bool ULock::TryUnlock(/*UnlockerType*/ ELockType Unlocker) {
	return lockType == Unlocker;
}