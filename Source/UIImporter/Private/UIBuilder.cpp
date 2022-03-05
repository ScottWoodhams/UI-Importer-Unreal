#include "UIBuilder.h"

#include "AssetToolsModule.h"
#include "ComponentBuilder.h"
#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "IAssetTools.h"
#include "ImageBuilder.h"
#include "TextBuilder.h"
#include "UIFontLibrary.h"
#include "WidgetBlueprint.h"
#include "WidgetBlueprintFactory.h"
#include "WidgetBuilderUtilities.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "UIComponentLibrary.h"

UIBuilder::UIBuilder()
{
}

void UIBuilder::Run(const FAssetData* AssetData, const UDataTable* DataTable) const
{
	FString ContentDir = AssetData->PackagePath.ToString() + "/";
	TTuple<FString, UWidgetBlueprint*> WidgetBlueprint = CreateWidgetBlueprint(AssetData);

	if(WidgetBlueprint.Value != nullptr)
	{
		UpdateWidgetBlueprint(DataTable, WidgetBlueprint.Value, ContentDir);
		SaveBlueprintAsset(WidgetBlueprint.Key);
	}

}

TTuple<FString, UWidgetBlueprint*> UIBuilder::CreateWidgetBlueprint(const FAssetData* AssetData) const
{

	FString AssetPath = AssetData->PackagePath.ToString() + "/";

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>(AssetToolsModuleName).Get();
	FString PackagePath = AssetPath;
	UClass* AssetClass = UWidgetBlueprint::StaticClass();
	UFactory* AssetFactory = NewObject<UWidgetBlueprintFactory>();

	FString AssetName = "WBP_" + AssetData->AssetName.ToString();

	/*AssetTools.CreateUniqueAssetName(
		PackagePath,
		CreatedUniqueBlueprintSuffix,
		AssetPath,
		AssetName);*/

	if(UEditorAssetLibrary::DoesAssetExist(AssetPath) == false)
	{
		FString Path = "";
		FString Name = "";

		UWidgetBlueprint* UIBlueprintAsset = Cast<UWidgetBlueprint>(AssetTools.CreateAsset(
			AssetName,
			AssetPath,
			AssetClass,
			AssetFactory));

		return TTuple<FString, UWidgetBlueprint*>(AssetPath, UIBlueprintAsset);
	}

	return TTuple<FString, UWidgetBlueprint*>("", nullptr);
}

void UIBuilder::UpdateWidgetBlueprint(const UDataTable* DataTable, const UWidgetBlueprint* WidgetBlueprint, FString ContentDir) const
{
	UWidgetTree* WidgetTree = WidgetBlueprint->WidgetTree;
	WidgetTree->Modify();

	//create root panel to add widgets to
	UCanvasPanel* CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>();
	const TMap<FName, uint8*> Data = DataTable->GetRowMap();
	TArray<unsigned char*> ValueArray;
	Data.GenerateValueArray(ValueArray);

	UUIFontLibrary* FontLibrary = Cast<UUIFontLibrary>(UEditorAssetLibrary::LoadAsset(FontLibraryPath));
	UUIComponentLibrary* ComponentLibrary = Cast<UUIComponentLibrary>(UEditorAssetLibrary::LoadAsset(FontLibraryPath));

	//loop through the array backwards as we create the widgets to keep correct depth order
	for(int32 i = ValueArray.Num(); i --> 0;)
	{
		const FUILayerData* LayerData = reinterpret_cast<FUILayerData*>(ValueArray[i]);

		if(UWidgetBuilderUtilities::IsImageLayer(LayerData->LayerType))
		{
			UImageBuilder::CreateWidget(LayerData, ContentDir, WidgetTree, CanvasPanel);
		}
		else if(LayerData->LayerType == text)
		{
			UTextBuilder::CreateWidget(LayerData, WidgetTree, CanvasPanel, FontLibrary);
		}
		else if(LayerData->IsComponent)
		{
			UComponentBuilder::CreateWidget(LayerData,WidgetTree,CanvasPanel, ComponentLibrary);
		}
	}

	WidgetTree->RootWidget = CanvasPanel;
}

void UIBuilder::SaveBlueprintAsset(const FString AssetPath)
{
	UEditorAssetLibrary::SaveAsset(AssetPath, true);
}