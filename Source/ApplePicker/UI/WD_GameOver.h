// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WD_GameOver.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API UWD_GameOver : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UButton* BTRetry;

	UPROPERTY(meta = (BindWidget))
	UButton* BTQuit;

	UFUNCTION()
	void OnBTRetryPressed();

	UFUNCTION()
	void OnBTQuitPressed();
	
};

