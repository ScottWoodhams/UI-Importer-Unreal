// Fill out your copyright notice in the Description page of Project Settings.


#include "UIComponentLibrary.h"

UUserWidget* UUIComponentLibrary::GetComponent(FString ComponentName)
{
	for(const FUIComponent Comp : Components)
	{
		if(Comp.ComponentName == ComponentName)
		{
			return Comp.WidgetBlueprint;
		}
	}

	return nullptr;
}
