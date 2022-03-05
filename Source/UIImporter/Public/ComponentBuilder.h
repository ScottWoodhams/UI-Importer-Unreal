// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIComponentLibrary.h"
#include "DataStructure.h"
#include "Components/CanvasPanel.h"
#include "ComponentBuilder.generated.h"

/**
 *
 */
UCLASS()
class UIIMPORTER_API UComponentBuilder : public UObject
{
	GENERATED_BODY()
public:
	static void CreateWidget(const FUILayerData* LayerData, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas, UUIComponentLibrary* ComponentLibrary);
private:
	static void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* CanvasSlot);

};
