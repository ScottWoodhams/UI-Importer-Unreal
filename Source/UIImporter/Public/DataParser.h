#pragma once

#include "DataParser.generated.h"

UCLASS()
class UDataParser : public UObject
{
	GENERATED_BODY()
public:
	static UDataTable* ReturnValidData(const FAssetData* AssetData);

};
