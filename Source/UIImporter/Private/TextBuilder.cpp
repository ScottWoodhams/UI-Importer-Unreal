﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "TextBuilder.h"

#include "WidgetBuilderUtilities.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/TextBlock.h"



void UTextBuilder::CreateWidget(const FUILayerData* LayerData,
	UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas)
{
	UTextBlock* TextBlock = BPWidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
	UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(TextBlock);
	SetSlotProperties(LayerData, CanvasSlot);
	SetWidgetProperties(TextBlock, LayerData);
}

void UTextBuilder::SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot)
{
	UWidgetBuilderUtilities::SetSlotDefaultProperties(LayerData, CanvasSlot);

	if(LayerData->TextDescriptor.Type != "point")
	{
		CanvasSlot->SetAlignment(FVector2D(0.0f,0.0f));
	}
}

void UTextBuilder::SetWidgetProperties(UTextBlock* TextBlock, const FUILayerData* LayerData)
{
	//todo set up font library
	//TextBlock->Font = LayerData.TextDescriptor.FontName

	TextBlock->Text = FText::FromString(LayerData->TextDescriptor.TextKey);
	FSlateColor TextColor = FSlateColor(LayerData->TextDescriptor.Color);
	TextBlock->ColorAndOpacity = TextColor;
	FSlateFontInfo Font = FSlateFontInfo();
	Font.Size = LayerData->TextDescriptor.Size;
	TextBlock->Font = Font;
}