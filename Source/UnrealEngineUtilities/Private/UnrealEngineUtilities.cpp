// Copyright by Free2Play-Entertainment (2020)

#include "UnrealEngineUtilities.h"
#include "UnrealEngineUtilitiesStyle.h"
#include "UnrealEngineUtilitiesCommands.h"
#include "ToolMenus.h"
#include "UnrealEdGlobals.h"

static const FName UnrealEngineUtilitiesTabName("UnrealEngineUtilities");

#define LOCTEXT_NAMESPACE "FUnrealEngineUtilitiesModule"

void FUnrealEngineUtilitiesModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FUnrealEngineUtilitiesStyle::Initialize();
	FUnrealEngineUtilitiesStyle::ReloadTextures();

	FUnrealEngineUtilitiesCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FUnrealEngineUtilitiesCommands::Get().RestartAction,
		FExecuteAction::CreateRaw(this, &FUnrealEngineUtilitiesModule::RestartEditor),
		FCanExecuteAction()
	);
	
	PluginCommands->MapAction(
		FUnrealEngineUtilitiesCommands::Get().ReinitAction,
		FExecuteAction::CreateRaw(this, &FUnrealEngineUtilitiesModule::ReinitializeEditor),
		FCanExecuteAction()
	);

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FUnrealEngineUtilitiesModule::RegisterMenus));
}

void FUnrealEngineUtilitiesModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FUnrealEngineUtilitiesStyle::Shutdown();

	FUnrealEngineUtilitiesCommands::Unregister();
}

void FUnrealEngineUtilitiesModule::RestartEditor()
{
	FUnrealEdMisc::Get().RestartEditor(false);
}

void FUnrealEngineUtilitiesModule::ReinitializeEditor()
{
	EditorReinit();
}

void FUnrealEngineUtilitiesModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.File");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("Project");
			Section.AddMenuEntryWithCommandList(FUnrealEngineUtilitiesCommands::Get().RestartAction, PluginCommands);
			Section.AddMenuEntryWithCommandList(FUnrealEngineUtilitiesCommands::Get().ReinitAction, PluginCommands);
		}
	}
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FUnrealEngineUtilitiesModule, UnrealEngineUtilities)