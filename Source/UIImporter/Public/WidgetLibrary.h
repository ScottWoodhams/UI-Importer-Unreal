// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetLibrary.generated.h"

USTRUCT(BlueprintType)
struct FWidgetEntry
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (TitleProperty = "Name"))
	FString Name;
	UPROPERTY(EditAnywhere, meta = (TitleProperty = "Widget"))
	UUserWidget* Widget;
};

/**
 *
 */
UCLASS()
class UIIMPORTER_API UWidgetLibrary : public UPrimaryDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TArray<FWidgetEntry> Entries;

	UUserWidget* GetWidgetFromName(FString Name);
};
