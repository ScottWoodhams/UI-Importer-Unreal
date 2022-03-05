// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructure.h"
#include "Components/CanvasPanel.h"
#include "Components/TextBlock.h"
#include "TextBuilder.generated.h"

/**
 *
 */
UCLASS()
class UIIMPORTER_API UTextBuilder : public UObject
{
	GENERATED_BODY()

public:
	static void CreateWidget(const FUILayerData* LayerData, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas);
private:
	static void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot);
	static void SetWidgetProperties(UTextBlock* TextBlock, const FUILayerData* LayerData);
};
