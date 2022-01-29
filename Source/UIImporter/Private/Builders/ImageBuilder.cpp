#include "ImageBuilder.h"

#include "Components/CanvasPanelSlot.h"
#include "Components/Image.h"

void UImageBuilder::CreateWidget(const FUILayerData* LayerData, FString ContentDirectory, UWidgetTree* WidgetTree, UCanvasPanel* RootCanvas)
{
	UImage* Image = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
	UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(Image);

}

void UImageBuilder::SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot)
{
	/*Slot->SetAlignment(FVector2D(0.5f, 0.5f));
	FVector2D Position;
	Position.X = LayerData->Bounds.Right - LayerData->Bounds.Left;
	Position.Y = LayerData->Rect.Y;
	FVector2D Size;
	Size.X = LayerData->Bounds.Width;
	Size.Y = LayerData->Rect.Height;
	Slot->SetPosition(Position);
	Slot->SetSize(Size);*/
}
