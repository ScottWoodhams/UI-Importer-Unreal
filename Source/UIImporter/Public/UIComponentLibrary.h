// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/WidgetComponent.h"
#include "UIComponentLibrary.generated.h"


USTRUCT(BlueprintType)
struct UIIMPORTER_API FUIComponent
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FString ComponentName;
	UPROPERTY(EditAnywhere)
	UUserWidget* WidgetBlueprint;
};

/**
 *
 */
UCLASS()
class UIIMPORTER_API UUIComponentLibrary : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
	TArray<FUIComponent> Components;

	UUserWidget* GetComponent(FString ComponentName);
};
