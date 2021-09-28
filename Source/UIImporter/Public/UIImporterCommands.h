// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "UIImporterStyle.h"

class FUIImporterCommands : public TCommands<FUIImporterCommands>
{
public:

	FUIImporterCommands()
		: TCommands<FUIImporterCommands>(TEXT("UIImporter"), NSLOCTEXT("Contexts", "UIImporter", "UIImporter Plugin"), NAME_None, FUIImporterStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenPluginWindow;
};