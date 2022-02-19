#include "UIBuilder.h"

#include "AssetToolsModule.h"
#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "IAssetTools.h"
#include "WidgetBlueprint.h"
#include "WidgetBlueprintFactory.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"

UIBuilder::UIBuilder()
{
}

void UIBuilder::Run(FAssetData* AssetData, const UDataTable* DataTable)
{
	FString AssetPath = AssetData->PackagePath.ToString() + "/";
	TTuple<FString, UWidgetBlueprint*> WidgetBlueprint = CreateWidgetBlueprint(AssetData);

	if(WidgetBlueprint.Value != nullptr)
	{
		UpdateWidgetBlueprint(DataTable, WidgetBlueprint.Value);
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

void UIBuilder::UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint)
{
	UWidgetTree* WidgetTree = WidgetBlueprint->WidgetTree;
	WidgetTree->Modify();

	//create root panel to add widgets to
	UCanvasPanel* CanvasPanel = WidgetTree->ConstructWidget<UCanvasPanel>();
	TMap<FName, uint8*> Data = DataTable->GetRowMap();
	TArray<unsigned char*> ValueArray;
	Data.GenerateValueArray(ValueArray);

	//loop through the array backwards as we create the widgets to keep correct depth order
	for(int32 i = ValueArray.Num(); i --> 0;)
	{
		const FUILayerData* LayerData = reinterpret_cast<FUILayerData*>(ValueArray[i]);

		switch (LayerData->LayerType)
		{
		case ELayerKind::text:
			//todo implement text builder
			break;
		case ELayerKind::pixel:
			//todo implement image builder

			break;
			default: break;

		}
	}

	WidgetTree->RootWidget = CanvasPanel;

}

void UIBuilder::SaveBlueprintAsset(FString AssetPath)
{
	UEditorAssetLibrary::SaveAsset(AssetPath, true);
}