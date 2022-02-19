// Fill out your copyright notice in the Description page of Project Settings.


#include "ImageBuilder.h"

#include "EditorAssetLibrary.h"
#include "UIImporter.h"
#include "WidgetBuilderUtilities.h"

void UImageBuilder::CreateWidget(const FUILayerData* LayerData, const FString UIContentDirectory, UWidgetTree* BPWidgetTree, UCanvasPanel* RootCanvas)
{
	UImage* Image = BPWidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
	UCanvasPanelSlot* CanvasSlot = RootCanvas->AddChildToCanvas(Image);
	SetSlotProperties(LayerData, CanvasSlot);
	SetWidgetProperties(Image, LayerData, UIContentDirectory);
}

void UImageBuilder::SetSlotProperties(const FUILayerData* LayerData, UCanvasPanelSlot* Slot)
{
	UWidgetBuilderUtilities::SetSlotDefaultProperties(LayerData, Slot);
}

void UImageBuilder::SetWidgetProperties(UImage* Image, const FUILayerData* LayerData,
										  const FString UIContentDirectory)
{

	FMargin Margin;
	Margin.Bottom = LayerData->Slices.Bottom;
	Margin.Left = LayerData->Slices.Left;
	Margin.Right = LayerData->Slices.Right;
	Margin.Top = LayerData->Slices.Top;

	Image->Brush.DrawAs = LayerData->SliceType != "None" ? ESlateBrushDrawType::Box : ESlateBrushDrawType::Image;

	const FString TextureName = LayerData->Name;
	const FString TexturePath = UIContentDirectory + "/" + TextureName + "." + TextureName;

	if (UEditorAssetLibrary::DoesAssetExist(TexturePath) == false)
	{
		UE_LOG(LogUIBuilder, Error, TEXT("File could not be found at: %s"), *TexturePath);
		return;
	}

	Image->SetBrushFromTexture(Cast<UTexture2D>(UEditorAssetLibrary::LoadAsset(TexturePath)));
	Image->Brush.Margin = Margin;

}
