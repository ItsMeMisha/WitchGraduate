// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class FLocks
{
public:
	enum ELockType {
		None = 0,
		Lockpick
	};

	FLocks();
	~FLocks();
};
