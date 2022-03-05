#include "DataParser.h"
#include "DataStructure.h"
#include "EditorAssetLibrary.h"
#include "UIBuilder.h"
#include "Misc/AutomationTest.h"

class UIBuilder;
IMPLEMENT_SIMPLE_AUTOMATION_TEST(WidgetBuilder, "UIImportDev.UIImporter.Source.UIImporter.Private.Tests.WidgetBuilder",
                                 EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool WidgetBuilder::RunTest(const FString& Parameters)
{
	const FString TestObjectPath = FString("");
	const UDataTable* Table = Cast<UDataTable>(UEditorAssetLibrary::LoadAsset(TestObjectPath));

	const UIBuilder* UIBuilder = NewObject<class UIBuilder>();
	const FAssetData AssetData= FAssetData(UEditorAssetLibrary::LoadAsset(TestObjectPath));
	UIBuilder->Run(&AssetData, Table);
	
	return true;
}
