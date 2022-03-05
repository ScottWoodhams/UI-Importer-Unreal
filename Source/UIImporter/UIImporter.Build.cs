// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UIImporter : ModuleRules
{
	public UIImporter(ReadOnlyTargetRules target) : base(target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicIncludePaths.AddRange(
			new string[] {
				// ... add public include paths required here ...
			}
			);


		PrivateIncludePaths.AddRange(
			new string[] {
				// ... add other private include paths required here ...
			}
			);


		PublicDependencyModuleNames.AddRange(
			new[]
			{
				"Core",
				"UMG",
			}
			);


		PrivateDependencyModuleNames.AddRange(
			new[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"UnrealEd",
				"EditorScriptingUtilities",
				"Blutility",
				"UMG",
				"UMGEditor",
				"Json",
				"PropertyEditor",
				"EditorWidgets",
				"EditorStyle",
				"Projects",
				"InputCore",
				"UnrealEd",
				"ToolMenus",
				"FontEditor"
			}
			);


		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}
