// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"
class AAPPlayer;
/**
 * 
 */
UCLASS()
class APPLEPICKER_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
public:
	UPROPERTY()
	AAPPlayer* PlayerPawn;

	UFUNCTION()
	void OnAxisEventLeftRight(float Axis);

	UFUNCTION()
	void OnActionEventPause();
	

	
};
