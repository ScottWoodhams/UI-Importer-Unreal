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

void UIBuilder::Run(FAssetData* AssetData, const UDataTable* DataTable)
{

	UWidgetBlueprint* WidgetBlueprint = CreateWidgetBlueprint(AssetData);
	UpdateWidgetBlueprint(DataTable, WidgetBlueprint);
}

UWidgetBlueprint* UIBuilder::CreateWidgetBlueprint(FAssetData* AssetData)
{
	//todo get file name and directory
	FString AssetPath = AssetData->PackagePath.ToString() + "/";


	//todo create widget blueprint
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

		auto UIBlueprintAsset = Cast<UWidgetBlueprint>(AssetTools.CreateAsset(
			AssetName,
			AssetPath,
			AssetClass,
			AssetFactory));

		return UIBlueprintAsset;
	}

	return nullptr;
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
		/*switch (LayerData->LayerType)
		{
			default: break;

		}*/
	}

}
