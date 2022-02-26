// Fill out your copyright notice in the Description page of Project Settings.


#include "ComponentLibrary.h"

UWidgetBlueprint* UComponentLibrary::GetComponent(FString ComponentName)
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
