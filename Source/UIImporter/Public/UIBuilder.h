#pragma once
#include "WidgetBlueprint.h"

class UIBuilder : public UObject
{
public:

	void Run(FAssetData* AssetData, const UDataTable* DataTable);

private:
	UWidgetBlueprint* CreateWidgetBlueprint(FAssetData* AssetData);
	void UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint);


	const FString CreatedUniqueBlueprintSuffix = "WBP";
	const FName AssetToolsModuleName = "AssetToolsModuleName";
};
