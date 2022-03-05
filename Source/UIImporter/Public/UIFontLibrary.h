// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UIFontLibrary.generated.h"

/**
 *
 */
UCLASS()
class UIIMPORTER_API UUIFontLibrary : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	TArray<UFont*> Fonts;

	const UFont* GetFont(const FString FontName);
};
