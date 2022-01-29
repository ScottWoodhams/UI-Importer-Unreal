#pragma once
#include "DataStructure.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "ImageBuilder.generated.h"

UCLASS()
class UImageBuilder : public UObject
{
public:
	GENERATED_BODY()

	void CreateWidget(const FUILayerData* LayerData, FString ContentDirectory, UWidgetTree* WidgetTree, UCanvasPanel* RootCanvas);

	void SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot);
};
