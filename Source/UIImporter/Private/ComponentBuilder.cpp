// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentBuilder.h"

#include "WidgetBuilderUtilities.h"

void UComponentBuilder::CreateWidget(const FUILayerData* LayerData, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas)
{
	UWidget* TextBlock = BPWidgetTree->ConstructWidget<UWidget>(UWidget::StaticClass());
	UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(TextBlock);
	SetSlotProperties(LayerData, CanvasSlot);
	
}

void UComponentBuilder::SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot)
{
	UWidgetBuilderUtilities::SetSlotDefaultProperties(LayerData, CanvasSlot);
}
