// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PlayerGameHud.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API UPlayerGameHud : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;
	
public:
	UFUNCTION(BlueprintCallable)
	void SetScore(int Score);

	UFUNCTION(BlueprintCallable)
	void SetHP(int HP);

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock * TextScore;

	UPROPERTY(meta = (BindWidget))
	UTextBlock * TextHP;
};
