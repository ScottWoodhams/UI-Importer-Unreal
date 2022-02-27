// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentBuilder.h"

#include "UIComponentLibrary.h"
#include "WidgetBuilderUtilities.h"
#include "Blueprint/WidgetTree.h"

void UComponentBuilder::CreateWidget(const FUILayerData* LayerData, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas, UUIComponentLibrary* ComponentLibrary)
{
	UUserWidget* UserWidget = BPWidgetTree->ConstructWidget<UUserWidget>(
		ComponentLibrary->GetComponent(LayerData->Component)->GetClass());

	UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(UserWidget);
	SetSlotProperties(LayerData, CanvasSlot);
}

void UComponentBuilder::SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot)
{
	UWidgetBuilderUtilities::SetSlotDefaultProperties(LayerData, CanvasSlot);
}
