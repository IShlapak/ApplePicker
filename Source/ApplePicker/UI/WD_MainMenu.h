// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WD_MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API UWD_MainMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:

	UPROPERTY(meta = (BindWidget))
	UButton* BTPlay;

	UPROPERTY(meta = (BindWidget))
	UButton* BTOptions;

	UPROPERTY(meta = (BindWidget))
	UButton* BTQuit;

	UFUNCTION()
	void OnBTPlayClicked();
	
	UFUNCTION()
	void OnBTOptionsClicked();

	UFUNCTION()
	void OnBTQuitClicked();
};
