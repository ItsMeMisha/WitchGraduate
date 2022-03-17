// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class Locks
{
public:
	enum LockType {
		None = 0,
		Lockpick
	};

	Locks();
	~Locks();
};
