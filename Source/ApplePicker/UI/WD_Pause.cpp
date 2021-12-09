// Fill out your copyright notice in the Description page of Project Settings.


#include "WD_Pause.h"

#include "ApplePicker/APGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UWD_Pause::NativeConstruct()
{
	Super::NativeConstruct();
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	BTMenu->OnClicked.AddUniqueDynamic(this, &UWD_Pause::GoToMainMenu);
	BTResume->OnClicked.AddUniqueDynamic(this, &UWD_Pause::ResumeGame);
	
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeUIOnly());
		Controller->SetShowMouseCursor(true);
	}
}

void UWD_Pause::NativeDestruct()
{
	Super::NativeDestruct();
	UGameplayStatics::SetGamePaused(GetWorld(), false);
	
	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeGameOnly());
		Controller->SetShowMouseCursor(false);
	}
	
}

void UWD_Pause::GoToMainMenu()
{
	UGameplayStatics::OpenLevel(this, "MenuMap");
	//Cast<UAPGameInstance>(UGameplayStatics::GetGameInstance(this))->ShowMainMenu();
}

void UWD_Pause::ResumeGame()
{
	RemoveFromParent();
}
