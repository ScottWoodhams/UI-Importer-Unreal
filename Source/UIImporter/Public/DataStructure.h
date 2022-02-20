#pragma once

#include "DataStructure.generated.h"

UENUM()
enum ELayerKind
{
	any = 0,
	pixel = 1,
	adjustment = 2,
	text = 3,
	vector = 4,
	smartObject = 5,
	video = 6,
	group = 7,
	threeD = 8,
	gradient = 9,
	pattern = 10,
	solidColor = 11,
	background = 12,
	groupEnd = 13
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FSlices
{
	GENERATED_BODY()

	UPROPERTY()
	float Top;
	UPROPERTY()
	float Right;
	UPROPERTY()
	float Bottom;
	UPROPERTY()
	float Left;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FLayerBounds
{
	GENERATED_BODY()

	UPROPERTY()
	float Top;
	UPROPERTY()
	float Left;
	UPROPERTY()
	float Bottom;
	UPROPERTY()
	float Right;
	UPROPERTY()
	float Width;
	UPROPERTY()
	float Height;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FTextDescriptor
{
	GENERATED_BODY()

	UPROPERTY()
	FString FontName;
	UPROPERTY()
	float Size;
	UPROPERTY()
	FString TextKey;
	UPROPERTY()
	FColor Color;
	UPROPERTY()
	FString Type;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FFrameFXDescriptor
{
	GENERATED_BODY()

	UPROPERTY()
	int32 Size;
	UPROPERTY()
	FColor Color;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FDropShadowDescriptor
{
	GENERATED_BODY()

	UPROPERTY()
	float Distance;
	UPROPERTY()
	FColor Color;
	UPROPERTY()
	float Angle;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FUILayerData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadOnly, Category = General)
	FString Name;
	UPROPERTY(BlueprintReadOnly, Category = General)
	TEnumAsByte<ELayerKind> LayerType;
	UPROPERTY(BlueprintReadOnly, Category = General)
	FLayerBounds Bounds;
	UPROPERTY(BlueprintReadOnly, Category = General)
	bool IsComponent;
	UPROPERTY(BlueprintReadOnly, Category = General)
	FString Component = "";

	UPROPERTY(BlueprintReadOnly, Category = Image)
	FSlices Slices = FSlices();
	UPROPERTY(BlueprintReadOnly, Category = Image)
	FString SliceType = "";

	UPROPERTY(BlueprintReadOnly, Category = Text)
	FTextDescriptor TextDescriptor = FTextDescriptor();

	UPROPERTY(BlueprintReadOnly, Category = Outline)
	FFrameFXDescriptor FrameFXDescriptor = FFrameFXDescriptor();

	UPROPERTY(BlueprintReadOnly, Category = DropShown)
	FDropShadowDescriptor DropShadowDescriptor = FDropShadowDescriptor();
};
