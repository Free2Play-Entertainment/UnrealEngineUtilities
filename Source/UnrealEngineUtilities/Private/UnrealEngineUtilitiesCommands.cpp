// Copyright by Free2Play-Entertainment (2020)

#include "UnrealEngineUtilitiesCommands.h"

#define LOCTEXT_NAMESPACE "FUnrealEngineUtilitiesModule"

void FUnrealEngineUtilitiesCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "UnrealEngineUtilities", "Execute UnrealEngineUtilities action", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
