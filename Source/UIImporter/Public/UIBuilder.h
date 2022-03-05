#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "UIBuilder.generated.h"

UCLASS()
class UIIMPORTER_API UIBuilder : public UObject
{
	GENERATED_BODY()

public:
	UIBuilder();
	void Run(FAssetData* AssetData, const UDataTable* DataTable);

private:
	TTuple<FString, UWidgetBlueprint*> CreateWidgetBlueprint(FAssetData* AssetData);
	void UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint, FString ContentDir);
	void SaveBlueprintAsset(FString AssetPath);

	const FString CreatedUniqueBlueprintSuffix = "WBP";
	const FName AssetToolsModuleName = "AssetTools";
};
