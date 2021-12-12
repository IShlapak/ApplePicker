// Fill out your copyright notice in the Description page of Project Settings.


#include "MainPlayerController.h"

#include "APGameInstance.h"
#include "ApplePicker/Pawns/APPlayer.h"
#include "Kismet/GameplayStatics.h"

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	PlayerPawn = Cast<AAPPlayer>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

void AMainPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	InputComponent->BindAxis("LeftRight", this, &AMainPlayerController::OnAxisEventLeftRight);
	InputComponent->BindAction("Pause", EInputEvent::IE_Pressed, this, &AMainPlayerController::OnActionEventPause);
}

void AMainPlayerController::OnAxisEventLeftRight(float Axis)
{
	PlayerPawn->MoveByController(Axis);
}

void AMainPlayerController::OnActionEventPause()
{
	Cast<UAPGameInstance>(GetGameInstance())->ShowPause();
}
