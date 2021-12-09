// Fill out your copyright notice in the Description page of Project Settings.


#include "WD_Options.h"

#include "ApplePicker/APGameInstance.h"
#include "Kismet/GameplayStatics.h"

void UWD_Options::NativeConstruct()
{
	Super::NativeConstruct();

	BTBack->OnClicked.AddUniqueDynamic(this, &UWD_Options::OnBTBackClicked);
}

void UWD_Options::OnBTBackClicked()
{
	RemoveFromParent();
	Cast<UAPGameInstance>(UGameplayStatics::GetGameInstance(this))->ShowMainMenu();
}
