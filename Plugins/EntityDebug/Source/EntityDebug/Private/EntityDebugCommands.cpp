// Copyright Epic Games, Inc. All Rights Reserved.

#include "EntityDebugCommands.h"

#define LOCTEXT_NAMESPACE "FEntityDebugModule"

void FEntityDebugCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "EntityDebug", "Bring up EntityDebug window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
