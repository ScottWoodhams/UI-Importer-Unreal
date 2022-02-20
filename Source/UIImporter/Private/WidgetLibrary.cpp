// Fill out your copyright notice in the Description page of Project Settings.


#include "WidgetLibrary.h"

UUserWidget* UWidgetLibrary::GetWidgetFromName(const FString Name)
{
	for(FWidgetEntry Entry : Entries)
	{
		if(Entry.Name == Name)
		{
			return Entry.Widget;
		}
	}

	return nullptr;
}
