// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class LiquidXTestApp : ModuleRules
{
	public LiquidXTestApp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput", "GameFeatures" });
	}
}
