// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UI/WD_GameOver.h"
#include "UI/WD_Options.h"
#include "UI/WD_Pause.h"
#include "UI/WD_MainMenu.h"

#include "APGameInstance.generated.h"


/**
 * 
 */
UCLASS()
class APPLEPICKER_API UAPGameInstance : public UGameInstance
{
	GENERATED_BODY()


public:
	UAPGameInstance(const FObjectInitializer & ObjectInitializer);
	
	UFUNCTION(BlueprintCallable)
	void StartNewGame();
	
	UFUNCTION(BlueprintCallable)
	void ShowMainMenu();

	UFUNCTION(BlueprintCallable)
	void ShowOptions();

	UFUNCTION(BlueprintCallable)
	void ShowPause();

	UFUNCTION(BlueprintCallable)
	void GameOver();

protected:
	TSubclassOf<class UWD_Pause> InGamePauseClass;
	TSubclassOf<class UWD_Options> InGameOptionsClass;
	TSubclassOf<class UWD_GameOver> InGameGameOverClass;
	TSubclassOf<class UWD_MainMenu> InGameMainMenuClass;
	
	UWD_Pause* PauseWD;
	UWD_Options* OptionsWD;
	UWD_GameOver* GameOverWD;
	UWD_MainMenu* MainMenuWD;
	
};
