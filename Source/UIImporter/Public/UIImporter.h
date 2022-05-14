// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

DECLARE_LOG_CATEGORY_EXTERN(LogUIBuilder, Log, All);

class FToolBarBuilder;
class FMenuBuilder;


class FUIImporterModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command (by default it will bring up plugin window) */
	void OpenImporterTab() const;

	FAssetData S_AssetData;
	FString GetPath() const;
	void OnDataChanged(const FAssetData& InAssetData);

private:

	void RegisterMenus();
	void MakePullDownMenu(FMenuBarBuilder &MenuBuilder) const;
	void FillPullDownMenu(FMenuBuilder &MenuBuilder) const;
	TSharedRef<SDockTab> OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs);
	void MakeTabMenuEntry(FMenuBuilder& menuBuilder) const;
	void OpenFontLibrary() const;
	void OpenWidgetLibrary() const;
	TSharedPtr<FUICommandList> PluginCommands;

	const FString FontLibraryPath = "/UIImporter/UIFontLibrary.UIFontLibrary";
	const FString WidgetLibraryPath = "/UIImporter/UIComponentLibrary.UIComponentLibrary";
};
