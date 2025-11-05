// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

// ReSharper disable once InconsistentNaming
public class ReRPGTarget : TargetRules
{
	// ReSharper disable once InconsistentNaming
	public ReRPGTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_6;
		ExtraModuleNames.Add("ReRPG");
		
	}
}
