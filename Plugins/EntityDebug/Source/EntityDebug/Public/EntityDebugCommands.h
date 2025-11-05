// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/Commands/Commands.h"
#include "EntityDebugStyle.h"

class FEntityDebugCommands : public TCommands<FEntityDebugCommands>
{
public:

	FEntityDebugCommands()
		: TCommands<FEntityDebugCommands>(TEXT("EntityDebug"), NSLOCTEXT("Contexts", "EntityDebug", "EntityDebug Plugin"), NAME_None, FEntityDebugStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};