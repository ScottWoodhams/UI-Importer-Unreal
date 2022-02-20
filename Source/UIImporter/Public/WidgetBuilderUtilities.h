// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataStructure.h"
#include "Components/CanvasPanelSlot.h"
#include "UObject/Object.h"
#include "WidgetBuilderUtilities.generated.h"

/**
 *
 */
UCLASS()
class UIIMPORTER_API UWidgetBuilderUtilities : public UObject
{
	GENERATED_BODY()

public:
	static void SetSlotDefaultProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot);
	static bool IsImageLayer(ELayerKind LayerKind);
};
