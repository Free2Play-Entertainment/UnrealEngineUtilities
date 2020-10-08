// Copyright by Free2Play-Entertainment (2020)

#include "UnrealEngineUtilitiesCommands.h"

#define LOCTEXT_NAMESPACE "FUnrealEngineUtilitiesModule"

void FUnrealEngineUtilitiesCommands::RegisterCommands()
{
	UI_COMMAND(RestartAction, "Restart", "Restart the Editor", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(ReinitAction, "Reinitialize", "Reinitialize the Editor", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
