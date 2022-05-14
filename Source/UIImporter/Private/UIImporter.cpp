// Copyright Epic Games, Inc. All Rights Reserved.

#include "UIImporter.h"

#include "UIImporterStyle.h"
#include "UIImporterCommands.h"
#include "LevelEditor.h"
#include "SSkeletonWidget.h"
#include "Widgets/Docking/SDockTab.h"
#include "ToolMenus.h"
#include "PropertyCustomizationHelpers.h"
#include "SUIImporterWindow.h"

static const FName UIImporterTabName("UIImporter");

#define LOCTEXT_NAMESPACE "FUIImporterModule"
DEFINE_LOG_CATEGORY(LogUIBuilder);

void FUIImporterModule::StartupModule()
{
	if(!IsRunningCommandlet())
	{
		FUIImporterStyle::Initialize();
		FUIImporterStyle::ReloadTextures();

		FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>(FName("LevelEditor"));
		TSharedPtr<FExtensibilityManager> LevelEditorMenuExtensibilityManager = LevelEditorModule.
			GetMenuExtensibilityManager();
		
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender);
		
		MenuExtender->AddMenuBarExtension(
			"Help",
			EExtensionHook::After,
			nullptr,
			FMenuBarExtensionDelegate::CreateRaw(this, &FUIImporterModule::MakePullDownMenu));

		//register ui importer window
		FGlobalTabmanager::Get()->RegisterNomadTabSpawner(
		"UIImporter",
		FOnSpawnTab::CreateRaw(this, &FUIImporterModule::OnSpawnPluginTab))
			.SetGroup(FWorkspaceItem::NewGroup(FText::FromString("Menu Root")))
			.SetDisplayName(FText::FromString("UI Importer"))
			.SetTooltipText(FText::FromString("ToolTipText"));

		LevelEditorMenuExtensibilityManager->AddExtender(MenuExtender);
	}


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
	return SNew(SDockTab)
		.TabRole(NomadTab)
		[
			SNew(SUIImporterWindow)
		];
}

void FUIImporterModule::OnDataChanged(const FAssetData& AssetData)
{
	S_AssetData = AssetData;
}

FString FUIImporterModule::GetPath() const
{
	if (S_AssetData.IsValid())
	{
		return S_AssetData.ObjectPath.ToString();
	}
	return "";
}


void FUIImporterModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		{
			UToolMenu * Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu");
			FToolMenuSection& Section = Menu->FindOrAddSection("General");
			Section.AddMenuEntryWithCommandList(FUIImporterCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

}

void FUIImporterModule::MakePullDownMenu(FMenuBarBuilder& MenuBuilder) const
{
	MenuBuilder.AddPullDownMenu(
		FText::FromString("UIImporter"),
		FText::FromString("UIImporter tooltip"),
		FNewMenuDelegate::CreateRaw(this, &FUIImporterModule::FillPullDownMenu),
		FName("UIImporter"),
		FName("UImporter Tutorial")
	);
}


void FUIImporterModule::FillPullDownMenu(FMenuBuilder& MenuBuilder) const
{

	MenuBuilder.BeginSection(FName("Builder"), FText::FromString("BuilderWindow"));
	MenuBuilder.AddMenuEntry(
		FText::FromString("UIImporter Window"),
		FText::FromString("Opens the UIImporter Window"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FUIImporterModule::OpenImporterTab)));
	MenuBuilder.EndSection();

	MenuBuilder.BeginSection(FName("Access"),  FText::FromString("Access"));

	MenuBuilder.AddMenuEntry(
		FText::FromString("OpenFontLibrary"),
		FText::FromString("Opens the widget library asset"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FUIImporterModule::OpenFontLibrary)));

	MenuBuilder.AddMenuEntry(
		FText::FromString("Open Widget Library"),
		FText::FromString("Opens the widget library asset"),
		FSlateIcon(),
		FUIAction(FExecuteAction::CreateRaw(this, &FUIImporterModule::OpenWidgetLibrary)));
		

	MenuBuilder.EndSection();
}

void FUIImporterModule::MakeTabMenuEntry(FMenuBuilder& menuBuilder) const
{
	FGlobalTabmanager::Get()->PopulateTabSpawnerMenu(menuBuilder, "UIImporter");
}


void FUIImporterModule::OpenImporterTab() const
{
	FGlobalTabmanager::Get()->TryInvokeTab(UIImporterTabName);
}


void FUIImporterModule::OpenFontLibrary() const
{
	UAssetEditorSubsystem* AssetEditor = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	AssetEditor->OpenEditorForAsset(FontLibraryPath);
}

void FUIImporterModule::OpenWidgetLibrary() const
{
	UAssetEditorSubsystem* AssetEditor = GEditor->GetEditorSubsystem<UAssetEditorSubsystem>();
	AssetEditor->OpenEditorForAsset(WidgetLibraryPath);
}


#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUIImporterModule, UIImporter)
