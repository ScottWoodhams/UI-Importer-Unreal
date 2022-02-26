// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructure.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "UObject/Object.h"
#include "ComponentBuilder.generated.h"

/**
 * 
 */
UCLASS()
class UIIMPORTER_API UComponentBuilder : public UObject
{
	GENERATED_BODY()
	void CreateWidget(const FUILayerData* LayerData, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas);
private:
	static void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot);
	//static void SetWidgetProperties(UTextBlock* TextBlock, const FUILayerData* LayerData, UUIFontL
};
