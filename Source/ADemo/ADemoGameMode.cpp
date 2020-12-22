// Copyright Epic Games, Inc. All Rights Reserved.

#include "ADemoGameMode.h"
#include "ADemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

AADemoGameMode::AADemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
