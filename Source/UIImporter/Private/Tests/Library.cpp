#include "UIComponentLibrary.h"
#include "EditorAssetLibrary.h"
#include "UIBuilder.h"
#include "UIFontLibrary.h"
#include "Engine/Font.h"
#include "Misc/AutomationTest.h"


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFontLibraryAccess, "UIExporter.Libraries.FontLibraryAccessable", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FComponentLibraryAccess, "UIExporter.Libraries.ComponentLibraryAccessable", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLoadFont, "UIExporter.Libraries.LoadFont", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FLoadComponent, "UIExporter.Libraries.LoadComponent", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)


bool FFontLibraryAccess::RunTest(const FString& Parameters)
{
	UUIFontLibrary* FontLib = Cast<UUIFontLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/UIFontLibrary.UIFontLibrary"));
	return TestEqual(TEXT(""), FontLib != nullptr, true);
}

bool FComponentLibraryAccess::RunTest(const FString& Parameters)
{
	UUIComponentLibrary* CompLib = Cast<UUIComponentLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/UIComponentLibrary.UIComponentLibrary"));
	return TestEqual(TEXT(""), CompLib != nullptr, true);
}

bool FLoadFont::RunTest(const FString& Parameters)
{
	UUIFontLibrary* FontLib = Cast<UUIFontLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/UIFontLibrary.UIFontLibrary"));
	UFont* EngineRobotoFont = Cast<UFont>(UEditorAssetLibrary::LoadAsset("/Engine/EngineFonts/Roboto.Roboto"));
	FontLib->Fonts.Add(EngineRobotoFont);
	//"Regular" is the legacy font name for Roboto in Unreal
	const UFont* RetrievedFont = FontLib->GetFont("Regular");
	return TestNotNull(TEXT("Retrieves Roboto Fone"), RetrievedFont);
}

bool FLoadComponent::RunTest(const FString& Parameters)
{
	UUIComponentLibrary* CompLib = Cast<UUIComponentLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/UIComponentLibrary.UIComponentLibrary"));
	FUIComponent* TestComp = new FUIComponent();
	TestComp->ComponentName = "Test";
	TestComp->WidgetBlueprint = Cast<UUserWidget>(UEditorAssetLibrary::LoadAsset("/UIImporter/TestAssets/WBP_Test.WBP_Test"));
	CompLib->Components.Add(*TestComp);

	UUserWidget* LoadedComp = CompLib->GetComponent("Test");

	return TestNotNull(TEXT("Retrieves Test component"), LoadedComp);
}
