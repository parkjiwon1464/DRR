// Copyright Epic Games, Inc. All Rights Reserved.


#include "DRRGameModeBase.h"

ADRRGameModeBase::ADRRGameModeBase()
{
	//Super::AGameModeBase();
	// 
	//DefaultPawnClass Setting
	static ConstructorHelpers::FClassFinder<APawn> DefaultPawnClassRef(TEXT("/Script/DRR.PlayerCharacterBase"));	
	if (DefaultPawnClassRef.Class)
	{
		DefaultPawnClass = DefaultPawnClassRef.Class;
	}

	//PlayerControllerClass Setting
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(TEXT("/Script/DRR.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}

}
