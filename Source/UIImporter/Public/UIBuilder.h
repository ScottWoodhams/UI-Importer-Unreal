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
	void Run(const FAssetData* AssetData, const UDataTable* DataTable) const;
	FString FontLibraryPath = "/UIImporter/FontLibrary.FontLibrary";
	FString ComponentLibraryPath = "/UIImporter/ComponentLibrary.ComponentLibrary";

private:
	TTuple<FString, UWidgetBlueprint*> CreateWidgetBlueprint(const FAssetData* AssetData) const;
	void UpdateWidgetBlueprint(const UDataTable* DataTable, const UWidgetBlueprint* WidgetBlueprint, FString ContentDir) const;
	static void SaveBlueprintAsset(FString AssetPath);

	const FString CreatedUniqueBlueprintSuffix = "WBP";
	const FName AssetToolsModuleName = "AssetTools";
};
