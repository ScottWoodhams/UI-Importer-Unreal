// Fill out your copyright notice in the Description page of Project Settings.


#include "UIFontLibrary.h"

#include "UIImporter.h"
#include "Engine/Font.h"

const UFont* UUIFontLibrary::GetFont(const FString FontName)
{
	const FName WantedFontName = FName(FontName);
	for(const UFont* Font : Fonts)
	{
		if(Font->LegacyFontName == WantedFontName)
		{
			return Font;
		}
	}

	UE_LOG(LogUIBuilder, Warning, TEXT("No Foint found for %s"), FontName);
	return nullptr;
}
