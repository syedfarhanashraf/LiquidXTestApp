// Copyright Epic Games, Inc. All Rights Reserved.

#include "LiquidXTestAppGameMode.h"
#include "LiquidXTestAppCharacter.h"
#include "UObject/ConstructorHelpers.h"

ALiquidXTestAppGameMode::ALiquidXTestAppGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
