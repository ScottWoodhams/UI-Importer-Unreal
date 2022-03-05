#include "UIComponentLibrary.h"
#include "DataParser.h"
#include "UIBuilder.h"
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


IMPLEMENT_SIMPLE_AUTOMATION_TEST(FValidData, "UIExporter.ParseData.GeneralData", EAutomationTestFlags::EditorContext | EAutomationTestFlags::EngineFilter)

bool FValidData::RunTest(const FString& Parameters)
{
	return TestEqual(TEXT(""), (UDataParser::ReturnValidData(nullptr) != nullptr), true);
}
