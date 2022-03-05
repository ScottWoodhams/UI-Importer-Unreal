// Fill out your copyright notice in the Description page of Project Settings.


#include "UIFontLibrary.h"
#include "Engine/Font.h"

const UFont* UUIFontLibrary::GetFont(const FString FontName)
{
	const FName WantedFontName = FName(FontName);
	if(Fonts.Num() > 0)
	{
		for(const UFont* Font : Fonts)
		{
			if(Font->LegacyFontName == WantedFontName)
			{
				return Font;
			}
		}
	}
	
	return nullptr;
}
