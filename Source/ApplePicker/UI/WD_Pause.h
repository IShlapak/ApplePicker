// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/Button.h"
#include "WD_Pause.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API UWD_Pause : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;
	
public:

	UFUNCTION()
	void GoToMainMenu();
	
	UFUNCTION()
	void ResumeGame();
	
	UPROPERTY(meta = (BindWidget))
	UButton* BTResume;

	UPROPERTY(meta = (BindWidget))
	UButton* BTMenu;
};
