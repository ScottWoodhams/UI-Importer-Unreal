// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructure.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/Image.h"
#include "ImageBuilder.generated.h"

/**
 *
 */
UCLASS()
class UIIMPORTER_API UImageBuilder : public UObject
{
	GENERATED_BODY()
public:
	static void CreateWidget(const FUILayerData* LayerData, const FString UIContentDirectory, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas);

private:
	static void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot);
	static void SetWidgetProperties(UImage* Image, const FUILayerData* LayerData, const FString UIContentDirectory);
};
