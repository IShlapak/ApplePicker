// Fill out your copyright notice in the Description page of Project Settings.


#include "WD_MainMenu.h"

#include "ApplePicker/APGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UWD_MainMenu::NativeConstruct()
{
	Super::NativeConstruct();

	APlayerController* Controller = UGameplayStatics::GetPlayerController(this, 0);
	if(IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeUIOnly());
		Controller->SetShowMouseCursor(true);
	}
	if(IsValid(BTPlay))
	{
	    int i = 1;
	}
	BTPlay->OnClicked.AddUniqueDynamic(this, &UWD_MainMenu::OnBTPlayClicked);
	BTOptions->OnClicked.AddUniqueDynamic(this, &UWD_MainMenu::OnBTOptionsClicked);
	BTQuit->OnClicked.AddUniqueDynamic(this, &UWD_MainMenu::OnBTQuitClicked);
}

void UWD_MainMenu::OnBTPlayClicked()
{
	Cast<UAPGameInstance>(GetGameInstance())->StartNewGame();
}

void UWD_MainMenu::OnBTOptionsClicked()
{
	RemoveFromParent();
	Cast<UAPGameInstance>(GetGameInstance())->ShowOptions();
}

void UWD_MainMenu::OnBTQuitClicked()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}
