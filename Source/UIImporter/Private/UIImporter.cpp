// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIImporter.h"
#include "UIImporterStyle.h"
#include "UIImporterCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName UIImporterTabName("UIImporter");

#define LOCTEXT_NAMESPACE "FUIImporterModule"

void FUIImporterModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FUIImporterStyle::Initialize();
	FUIImporterStyle::ReloadTextures();

	FUIImporterCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FUIImporterCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FUIImporterModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FUIImporterModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(UIImporterTabName, FOnSpawnTab::CreateRaw(this, &FUIImporterModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FUIImporterTabTitle", "UIImporter"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FUIImporterModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FUIImporterStyle::Shutdown();

	FUIImporterCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(UIImporterTabName);
}

TSharedRef<SDockTab> FUIImporterModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FUIImporterModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("UIImporter.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FUIImporterModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(UIImporterTabName);
}

void FUIImporterModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FUIImporterCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FUIImporterCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUIImporterModule, UIImporter)