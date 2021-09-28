// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIImporterCommands.h"

#define LOCTEXT_NAMESPACE "FUIImporterModule"

void FUIImporterCommands::RegisterCommands()
{
	UI_COMMAND(OpenPluginWindow, "UIImporter", "Bring up UIImporter window", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
