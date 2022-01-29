// Fill out your copyright notice in the Description page of Project Settings.

#include "DataParser.h"

#include "DataStructure.h"
#include "UIImporter.h"


bool UDataParser::ValidateData(const FAssetData* AssetData, UDataTable& OutDataTable)
{
	UE_LOG(LogUIBuilder, Log, TEXT("Starting Data Validation"))

	UDataTable* Data = Cast<UDataTable>(AssetData->GetAsset());

	if(Data == nullptr)
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is not valid"))
		return false;
	}

	if(Data->RowStruct != FUILayerData::StaticStruct())
	{
		UE_LOG(LogUIBuilder, Error, TEXT("Data is not correct struct"))
		return false;
	}

	//OutDataTable = Data;

	return true;
}
