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
	void CreateWidget(const FUILayerData* LayerData, const FString UIContentDirectory, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas);

private:
	void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot);
	void SetWidgetProperties(UImage* Image, const FUILayerData* LayerData, const FString UIContentDirectory);
};
