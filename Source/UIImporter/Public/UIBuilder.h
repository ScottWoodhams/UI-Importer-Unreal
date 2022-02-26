#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "UObject/NoExportTypes.h"
#include "UIBuilder.generated.h"

UCLASS()
class UIIMPORTER_API UIBuilder : public UObject
{
	GENERATED_BODY()

public:
	UIBuilder();
	void Run(FAssetData* AssetData, const UDataTable* DataTable);
	FString FontLibraryPath = "/UIImporter/FontLibrary.FontLibrary";
	FString ComponentLibraryPath = "/UIImporter/ComponentLibrary.ComponentLibrary";

private:
	TTuple<FString, UWidgetBlueprint*> CreateWidgetBlueprint(FAssetData* AssetData);
	void UpdateWidgetBlueprint(const UDataTable* DataTable, UWidgetBlueprint* WidgetBlueprint, FString ContentDir);
	void SaveBlueprintAsset(FString AssetPath);

	const FString CreatedUniqueBlueprintSuffix = "WBP";
	const FName AssetToolsModuleName = "AssetTools";
};
