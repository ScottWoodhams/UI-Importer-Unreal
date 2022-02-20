#pragma once
#include "DataStructure.h"

#include "DataParser.generated.h"

UCLASS()
class UIIMPORTER_API UDataParser : public UObject
{
	GENERATED_BODY()
public:
	static bool IsBoundsValid(const FLayerBounds& Bounds);
	static UDataTable* ReturnValidData(const FAssetData* AssetData);

};
