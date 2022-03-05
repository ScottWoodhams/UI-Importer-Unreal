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

	UPROPERTY(EditAnywhere)
	float Top;
	UPROPERTY(EditAnywhere)
	float Right;
	UPROPERTY(EditAnywhere)
	float Bottom;
	UPROPERTY(EditAnywhere)
	float Left;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FLayerBounds
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Top;
	UPROPERTY(EditAnywhere)
	float Left;
	UPROPERTY(EditAnywhere)
	float Bottom;
	UPROPERTY(EditAnywhere)
	float Right;
	UPROPERTY(EditAnywhere)
	float Width;
	UPROPERTY(EditAnywhere)
	float Height;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FTextDescriptor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString FontName;
	UPROPERTY(EditAnywhere)
	float Size;
	UPROPERTY(EditAnywhere)
	FString TextKey;
	UPROPERTY(EditAnywhere)
	FColor Color;
	//todo should change to enum to ensure correct type
	UPROPERTY(EditAnywhere)
	FString Type;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FFrameFXDescriptor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	int32 Size;
	UPROPERTY(EditAnywhere)
	FColor Color;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FDropShadowDescriptor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	float Distance;
	UPROPERTY(EditAnywhere)
	FColor Color;
	UPROPERTY(EditAnywhere)
	float Angle;
};

USTRUCT(BlueprintType)
struct UIIMPORTER_API FUILayerData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = General)
	FString Name;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = General)
	TEnumAsByte<ELayerKind> LayerType;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = General)
	FLayerBounds Bounds;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = General)
	bool IsComponent;
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = General)
	FString Component = "";

	UPROPERTY(BlueprintReadWrite, EditAnywhere,Category = Image)
	FSlices Slices = FSlices();
	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = Image)
	FString SliceType = "";

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = Text)
	FTextDescriptor TextDescriptor = FTextDescriptor();

	UPROPERTY(BlueprintReadWrite,EditAnywhere, Category = Outline)
	FFrameFXDescriptor FrameFXDescriptor = FFrameFXDescriptor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = DropShown)
	FDropShadowDescriptor DropShadowDescriptor = FDropShadowDescriptor();
};
