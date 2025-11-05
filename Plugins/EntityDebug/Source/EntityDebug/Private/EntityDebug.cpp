// Copyright Epic Games, Inc. All Rights Reserved.

#include "EntityDebug.h"
#include "EntityDebugStyle.h"
#include "EntityDebugCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "ToolMenus.h"

static const FName EntityDebugTabName("EntityDebug");

#define LOCTEXT_NAMESPACE "FEntityDebugModule"

void FEntityDebugModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEntityDebugStyle::Initialize();
	FEntityDebugStyle::ReloadTextures();

	FEntityDebugCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEntityDebugCommands::Get().OpenPluginWindow,
		FExecuteAction::CreateRaw(this, &FEntityDebugModule::PluginButtonClicked),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FEntityDebugModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(EntityDebugTabName, FOnSpawnTab::CreateRaw(this, &FEntityDebugModule::OnSpawnPluginTab))
		.SetDisplayName(LOCTEXT("FEntityDebugTabTitle", "EntityDebug"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
}

void FEntityDebugModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FEntityDebugStyle::Shutdown();

	FEntityDebugCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(EntityDebugTabName);
}

TSharedRef<SDockTab> FEntityDebugModule::OnSpawnPluginTab(const FSpawnTabArgs& SpawnTabArgs)
{
	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code to {0} in {1} to override this window's contents"),
		FText::FromString(TEXT("FEntityDebugModule::OnSpawnPluginTab")),
		FText::FromString(TEXT("EntityDebug.cpp"))
		);

	return SNew(SDockTab)
		.TabRole(ETabRole::NomadTab)
		[
			// Put your tab content here!
			SNew(SBox)
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Center)
			[
				SNew(STextBlock)
				.Text(WidgetText)
			]
		];
}

void FEntityDebugModule::PluginButtonClicked()
{
	FGlobalTabmanager::Get()->TryInvokeTab(EntityDebugTabName);
}

void FEntityDebugModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEntityDebugCommands::Get().OpenPluginWindow, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar.PlayToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("PluginTools");
			{
				FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEntityDebugCommands::Get().OpenPluginWindow));
				Entry.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEntityDebugModule, EntityDebug)