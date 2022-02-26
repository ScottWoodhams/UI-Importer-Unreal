// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "WidgetBlueprint.h"
#include "Components/WidgetComponent.h"
#include "UObject/Object.h"
#include "ComponentLibrary.generated.h"


USTRUCT(BlueprintType)
struct UIIMPORTER_API FUIComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FString ComponentName;
	UPROPERTY(EditAnywhere)
	UWidgetBlueprint* WidgetBlueprint;
};

/**
 * 
 */
UCLASS()
class UIIMPORTER_API UComponentLibrary : public UDataAsset
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	TArray<FUIComponent> Components;

	UWidgetBlueprint* GetComponent(FString ComponentName);
};
