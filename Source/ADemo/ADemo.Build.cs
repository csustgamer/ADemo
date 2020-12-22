// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ADemo : ModuleRules
{
	public ADemo(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "GameplayAbilities", "GameplayTags", "GameplayTasks", "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
        PrivateDependencyModuleNames.AddRange(
            new string[] {
                "Slate",
                "SlateCore",
                "InputCore",
                "MoviePlayer"
            }
        );
    }
}
