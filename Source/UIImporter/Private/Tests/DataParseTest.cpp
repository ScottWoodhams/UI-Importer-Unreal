#include "DataParseTest.h"

#include "Misc/AutomationTest.h"
#include "Tests/AutomationEditorCommon.h"

/* Tests to include
 * todo can pass on valid data
 * todo can fail on invalid data
 * todo creates widget blueprint in correct directory
 * todo checks if creates all the layers from the data
 * todo checks font loading
 * todo checks component load and insert
 *
 */


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FValidGeneralData, "UIExporter.ParseData.GeneralData is Valid", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)


bool FValidGeneralData::RunTest(const FString& Parameters)
{
	TestEqual(TEXT("Test equal"), 123, 123);
	return true;
}
