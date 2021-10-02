// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"

/**
 *
 */
class UIIMPORTER_API SUIImporterWindow : public SCompoundWidget
{
public:
SLATE_BEGIN_ARGS(SUIImporterWindow)
		{
		}

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);

	FString GetPath() const;
	void OnDataChanged(const FAssetData& InAssetData);
	FReply RunBuilder();

	FAssetData AssetData;
	TSharedPtr<SButton> RunButton;

	const FText ButtonText = FText::FromString("Run");
	const FName ButtonTextCoreStyle = "EmbossedText";
};
