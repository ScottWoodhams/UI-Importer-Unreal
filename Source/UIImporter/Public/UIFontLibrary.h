﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UIFontLibrary.generated.h"

/**
 * 
 */
UCLASS()
class UIIMPORTER_API UUIFontLibrary : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	TArray<UFont*> Fonts;

	const UFont* GetFont(const FString FontName);
};
