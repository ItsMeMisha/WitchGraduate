// Copyright Epic Games, Inc. All Rights Reserved.

#include "WitchGraduateGameMode.h"
#include "WitchGraduatePlayerController.h"
#include "WitchGraduateCharacter.h"
#include "UObject/ConstructorHelpers.h"

AWitchGraduateGameMode::AWitchGraduateGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AWitchGraduatePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}