// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "WD_Options.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API UWD_Options : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

public:
	UPROPERTY(meta = (BindWidget))
	UButton* BTBack;

	UFUNCTION()
	void OnBTBackClicked();
	
};
