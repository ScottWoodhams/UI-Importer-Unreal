﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "SUIImporterWindow.h"

#include "DataParser.h"
#include "EditorAssetLibrary.h"
#include "SlateOptMacros.h"
#include "SAssetDropTarget.h"
#include "Widgets/Layout/SScrollBox.h"
#include "PropertyEditor/Private/PropertyEditorHelpers.h"
#include "PropertyCustomizationHelpers.h"
#include "UIBuilder.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SUIImporterWindow::Construct(const FArguments& InArgs)
{
	ChildSlot
	[
		SNew(SScrollBox)

		+ SScrollBox::Slot()
		  .VAlign(VAlign_Top)
		  .Padding(5)
		[

			SNew(SBorder)
				.BorderBackgroundColor(FColor(192, 192, 192, 255))
				.Padding(15.0f)
			[
				SNew(SVerticalBox)

				//Asset Selection
				+ SVerticalBox::Slot()
				[
					SNew(SObjectPropertyEntryBox)
						.OnObjectChanged(this, &SUIImporterWindow::OnDataChanged)
						.ObjectPath(this, &SUIImporterWindow::GetPath)
						.AllowedClass(UDataTable::StaticClass())
						.DisplayThumbnail(true)
						.DisplayBrowse(true)
				]

				//button to run importer
				+ SVerticalBox::Slot()
				.Padding(0, 10, 0, 0)
				[

					SAssignNew(RunButton, SButton)

					.OnClicked_Raw(this, &SUIImporterWindow::RunBuilder)
					[
						SNew(STextBlock)
							.Font(FCoreStyle::Get().GetFontStyle(ButtonTextCoreStyle))
							.Text(ButtonText)
							.Justification(ETextJustify::Center)
					]
				]
				+ SVerticalBox::Slot().Padding(0, 100, 0,0)
				[
					SAssignNew(InformationBlock, STextBlock)
					.Font(FCoreStyle::Get().GetFontStyle(ButtonTextCoreStyle))
					.Text(this, &SUIImporterWindow::GetInformationText)
					.Justification(ETextJustify::Left)
				]
				
			]
		]
	];
}

void SUIImporterWindow::OnDataChanged(const FAssetData& InAssetData)
{
	AssetData = InAssetData;
	UE_LOG(LogCore, Warning, TEXT("Object changed"))
	InformationBlockText = FText::FromString("Object changed");
	InformationBlock->SetText(DataToString());
}

FText SUIImporterWindow::DataToString()
{
	FString Info = "";

	FString ObjectPath = AssetData.ObjectPath.ToString();
	UDataTable* Table = Cast<UDataTable>(UEditorAssetLibrary::LoadAsset(ObjectPath));
	TArray<FUILayerData*> Rows;
	Table->GetAllRows("",Rows );
	uint32 num = Rows.Num();

	Info = Info.Format(TEXT("Number of Layers: {0}"), {num});
	
	return FText::FromString(Info);
}

FText SUIImporterWindow::GetInformationText() const
{
	return InformationBlockText;
}

FString SUIImporterWindow::GetPath() const
{
	if (AssetData.IsValid())
	{
		return AssetData.ObjectPath.ToString();
	}

	return "";
}

FReply SUIImporterWindow::RunBuilder()
{
	if (AssetData != nullptr)
	{
		UDataTable* Table = UDataParser::ReturnValidData(&AssetData);

		if (Table != nullptr)
		{
			UIBuilder* UIBuilder = NewObject<class UIBuilder>();
			UIBuilder->Run(&AssetData, Table);
		}
	}

	return FReply::Handled();
}


END_SLATE_FUNCTION_BUILD_OPTIMIZATION
