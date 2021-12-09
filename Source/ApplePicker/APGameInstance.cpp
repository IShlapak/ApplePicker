// Fill out your copyright notice in the Description page of Project Settings.


#include "APGameInstance.h"

#include "Kismet/GameplayStatics.h"

UAPGameInstance::UAPGameInstance(const FObjectInitializer& ObjectInitializer)
{
	static ConstructorHelpers::FClassFinder<UWD_Pause> InGameBPPauseClass(TEXT("/Game/Blueprints/CPP/UI/WBP_Payse"));
	InGamePauseClass = InGameBPPauseClass.Class;

	static ConstructorHelpers::FClassFinder<UWD_Options> InGameBPOptionsClass(TEXT("/Game/Blueprints/CPP/UI/WBP_Options"));
	InGameOptionsClass = InGameBPOptionsClass.Class;

	static ConstructorHelpers::FClassFinder<UWD_GameOver> InGameBPGameOverClass(TEXT("/Game/Blueprints/CPP/UI/WBP_GameOver"));
	InGameGameOverClass = InGameBPGameOverClass.Class;

	static ConstructorHelpers::FClassFinder<UWD_MainMenu> InGameBPMainMenuClass(TEXT("/Game/Blueprints/CPP/UI/WBP_MainMenu"));
	InGameMainMenuClass = InGameBPMainMenuClass.Class;

	
}

void UAPGameInstance::StartNewGame()
{
	UGameplayStatics::OpenLevel(this, "Main");

	APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);
	if(IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeGameOnly());
		Controller->SetShowMouseCursor(false);
	}
}

void UAPGameInstance::ShowMainMenu()
{
	MainMenuWD = CreateWidget<UWD_MainMenu>(this, InGameMainMenuClass);
	MainMenuWD->AddToViewport();
}

void UAPGameInstance::ShowOptions()
{
	OptionsWD = CreateWidget<UWD_Options>(this, InGameOptionsClass);
	OptionsWD->AddToViewport();
}

void UAPGameInstance::ShowPause()
{
	PauseWD = CreateWidget<UWD_Pause>(this, InGamePauseClass);
	PauseWD->AddToViewport();
}

void UAPGameInstance::GameOver()
{
	GameOverWD = CreateWidget<UWD_GameOver>(this, InGameGameOverClass);
	GameOverWD->AddToViewport();
}
