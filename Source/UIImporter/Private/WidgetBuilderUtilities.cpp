// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetBuilderUtilities.h"

void UWidgetBuilderUtilities::SetSlotDefaultProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot)
{
	Slot->SetAlignment(FVector2D(0.5f, 0.5f));
	FVector2D Position;
	Position.X = (LayerData->Bounds.Right + LayerData->Bounds.Left) * 0.5f;
	Position.Y = (LayerData->Bounds.Bottom + LayerData->Bounds.Top) * 0.5f;
	FVector2D Size;
	Size.X = LayerData->Bounds.Width;
	Size.Y = LayerData->Bounds.Height;
	Slot->SetPosition(Position);
	Slot->SetSize(Size);
}