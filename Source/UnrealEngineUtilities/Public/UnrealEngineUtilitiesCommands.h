// Copyright by Free2Play-Entertainment (2020)

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "UnrealEngineUtilitiesStyle.h"

class FUnrealEngineUtilitiesCommands : public TCommands<FUnrealEngineUtilitiesCommands>
{
public:

	FUnrealEngineUtilitiesCommands()
		: TCommands<FUnrealEngineUtilitiesCommands>(TEXT("UnrealEngineUtilities"), NSLOCTEXT("Contexts", "UnrealEngineUtilities", "UnrealEngineUtilities Plugin"), NAME_None, FUnrealEngineUtilitiesStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > ReinitAction;

	TSharedPtr< FUICommandInfo > RestartAction;
};
