#pragma once
#include "WidgetBlueprint.h"

class UIBuilder : public UObject
{
public:

	void Run(FAssetData* AssetData, const UDataTable* DataTable);

private:
	TTuple<FString, UWidgetBlueprint*> CreateWidgetBlueprint(FAssetData* AssetData);
	void UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint);
	void SaveBlueprintAsset(FString AssetPath);

	const FString CreatedUniqueBlueprintSuffix = "WBP";
	const FName AssetToolsModuleName = "AssetTools";
};
