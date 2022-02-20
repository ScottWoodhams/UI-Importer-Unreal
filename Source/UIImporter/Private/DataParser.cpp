// Fill out your copyright notice in the Description page of Project Settings.

#include "DataParser.h"

#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "UIImporter.h"
#include "WidgetBuilderUtilities.h"


bool UDataParser::IsBoundsValid(const FLayerBounds &Bounds)
{
	if(Bounds.Width < 1 || Bounds.Height < 1)
	{
		return false;
	}

	float XPos = (Bounds.Left + Bounds.Right) * 0.5f;
	float YPos = (Bounds.Top + Bounds.Bottom) * 0.5f;

	return ((XPos > 0 && FMath::IsFinite(XPos)) && (YPos > 0 && FMath::IsFinite(YPos)));
}

UDataTable* UDataParser::ReturnValidData(const FAssetData* AssetData)
{
	FString ObjectPath = AssetData->ObjectPath.ToString();
	UDataTable* Table = Cast<UDataTable>(UEditorAssetLibrary::LoadAsset(ObjectPath));

	if(Table == nullptr)
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is null"))
		return nullptr;
	}

	if(Table->RowStruct != FUILayerData::StaticStruct())
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is not correct struct"))
		return nullptr;
	}

	for (const TPair<FName, uint8*>& RowItr: Table->GetRowMap())
	{
		const FUILayerData* LayerData = reinterpret_cast<const FUILayerData*>(RowItr.Value);
		if(IsBoundsValid(LayerData->Bounds) == false)
		{
			UE_LOG(LogUIBuilder, Warning, TEXT("Layer %d bounds is invalid"), RowItr.Value);
		}

		if(UWidgetBuilderUtilities::IsImageLayer(LayerData->LayerType))
		{
			FString TexturePath = AssetData->PackagePath.ToString() + LayerData->Name;
			if(UEditorAssetLibrary::DoesAssetExist(TexturePath) == false)
			{
				UE_LOG(LogUIBuilder, Warning, TEXT("Could not find texture"), RowItr.Value);
			}


		}

	}



	return Table;
}
