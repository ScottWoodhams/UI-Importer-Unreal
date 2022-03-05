#include "UIBuilder.h"

#include "AssetToolsModule.h"
#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "IAssetTools.h"
#include "ImageBuilder.h"
#include "TextBuilder.h"
#include "WidgetBlueprint.h"
#include "WidgetBlueprintFactory.h"
#include "WidgetBuilderUtilities.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"

UIBuilder::UIBuilder()
{
}

void UIBuilder::Run(FAssetData* AssetData, const UDataTable* DataTable)
{
	FString ContentDir = AssetData->PackagePath.ToString() + "/";
	TTuple<FString, UWidgetBlueprint*> WidgetBlueprint = CreateWidgetBlueprint(AssetData);

	if(WidgetBlueprint.Value != nullptr)
	{
		UpdateWidgetBlueprint(DataTable, WidgetBlueprint.Value, ContentDir);
		SaveBlueprintAsset(WidgetBlueprint.Key);
	}

}

TTuple<FString, UWidgetBlueprint*> UIBuilder::CreateWidgetBlueprint(FAssetData* AssetData)
{

	FString AssetPath = AssetData->PackagePath.ToString() + "/";

	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>(AssetToolsModuleName).Get();
	const FString PackagePath;
	UClass* AssetClass = UWidgetBlueprint::StaticClass();
	UFactory* AssetFactory = NewObject<UWidgetBlueprintFactory>();

	FString AssetName;

	AssetTools.CreateUniqueAssetName(
		PackagePath,
		CreatedUniqueBlueprintSuffix,
		AssetPath,
		AssetName);

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

void UIBuilder::UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint, FString ContentDir)
{
	UWidgetTree* WidgetTree = WidgetBlueprint->WidgetTree;
	WidgetTree->Modify();

	//create root panel to add widgets to
	UCanvasPanel* CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>();
	const TMap<FName, uint8*> Data = DataTable->GetRowMap();
	TArray<unsigned char*> ValueArray;
	Data.GenerateValueArray(ValueArray);

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
			UTextBuilder::CreateWidget(LayerData, WidgetTree, CanvasPanel);
		}
		else if(LayerData->IsComponent)
		{
			//todo set up component workflow -- need component library and component builder

		}
		else
		{
			//we dont support any other type of layers to we create an empty widget
			//todo setup empty widget builder
		}
	}

	WidgetTree->RootWidget = CanvasPanel;
}

void UIBuilder::SaveBlueprintAsset(FString AssetPath)
{
	UEditorAssetLibrary::SaveAsset(AssetPath, true);
}