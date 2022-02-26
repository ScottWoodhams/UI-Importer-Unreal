#include "DataParseTest.h"

#include "ComponentLibrary.h"
#include "DataParser.h"
#include "EditorAssetLibrary.h"
#include "UIBuilder.h"
#include "UIFontLibrary.h"
#include "Misc/AutomationTest.h"

/* Tests to include
 * todo can pass on valid data
 * todo can fail on invalid data
 * todo creates widget blueprint in correct directory
 * todo checks if creates all the layers from the data
 * todo checks font loading
 * todo checks component load and insert
 *
 */


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FValidData, "UIExporter.ParseData.GeneralData is Valid", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FFontLibraryAccess, "UIExporter.Libraries.FontLibraryAccessable", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)
IMPLEMENT_SIMPLE_AUTOMATION_TEST(FComponentLibraryAccess, "UIExporter.Libraries.ComponentLibraryAccessable", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)


bool FValidData::RunTest(const FString& Parameters)
{
	return TestEqual(TEXT(""), (UDataParser::ReturnValidData(nullptr) != nullptr), true);
}

bool FFontLibraryAccess::RunTest(const FString& Parameters)
{
	UUIFontLibrary* FontLib = Cast<UUIFontLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/UIFontLibrary.UIFontLibrary"));
	
	return TestEqual(TEXT(""), FontLib != nullptr, true);
}

bool FComponentLibraryAccess::RunTest(const FString& Parameters)
{
	UComponentLibrary* CompLib = Cast<UComponentLibrary>(UEditorAssetLibrary::LoadAsset("/UIImporter/ComponentLibrary.ComponentLibrary"));
	return TestEqual(TEXT(""), CompLib != nullptr, true);

}
