// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "UI/PlayerGameHud.h"
#include "APGameState.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API AAPGameState : public AGameStateBase
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadWrite)
	bool Alive;

	UPROPERTY()
	int PlayerScore;

	UPROPERTY()
	UPlayerGameHud* PlayerHUD;
	
public:
	UFUNCTION(BlueprintCallable)
	void StartNewGame(UPlayerGameHud* HUD);
	
	UFUNCTION(BlueprintCallable)
	void AddScore(int AdditionalScore);

	
	
};
