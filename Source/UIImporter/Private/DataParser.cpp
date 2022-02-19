// Fill out your copyright notice in the Description page of Project Settings.

#include "DataParser.h"

#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "UIImporter.h"


UDataTable* UDataParser::ReturnValidData(const FAssetData* AssetData)
{
	UE_LOG(LogUIBuilder, Log, TEXT("Starting Data Validation"))
	FString ObjectPath = AssetData->ObjectPath.ToString();
	UDataTable* Table = Cast<UDataTable>(UEditorAssetLibrary::LoadAsset(ObjectPath));

	if(Datatable == nullptr)
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is not valid"))
		return false;
	}

	if(Datatable->RowStruct != FUILayerData::StaticStruct())
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is not correct struct"))
		return false;
	}

	return true;
}
