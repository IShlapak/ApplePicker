// Fill out your copyright notice in the Description page of Project Settings.


#include "WD_GameOver.h"

#include "ApplePicker/APGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UWD_GameOver::NativeConstruct()
{
	Super::NativeConstruct();

	BTRetry->OnClicked.AddUniqueDynamic(this, &UWD_GameOver::OnBTRetryPressed);
	BTQuit->OnClicked.AddUniqueDynamic(this, &UWD_GameOver::OnBTQuitPressed);

	APlayerController* Controller =  UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if(IsValid(Controller))
	{
		Controller->SetInputMode(FInputModeUIOnly());
		Controller->SetShowMouseCursor(true);
	}
}

void UWD_GameOver::OnBTRetryPressed()
{
	Cast<UAPGameInstance>(GetGameInstance())->StartNewGame();
	RemoveFromParent();
}

void UWD_GameOver::OnBTQuitPressed()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), nullptr, EQuitPreference::Quit, false);
}