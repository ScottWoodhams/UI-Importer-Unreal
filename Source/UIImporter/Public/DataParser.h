#pragma once

#include "DataParser.generated.h"

UCLASS()
class UDataParser : public UObject
{
	GENERATED_BODY()
public:
	static bool ValidateData(const FAssetData* AssetData, UDataTable* OutDataTable);

};
