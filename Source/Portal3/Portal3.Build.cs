// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Portal3 : ModuleRules
{
	public Portal3(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"HeadMountedDisplay", 
			"EnhancedInput" });

        PublicIncludePaths.AddRange(new string[] { "Portal3/FunctionLibraries" });
    }
}
