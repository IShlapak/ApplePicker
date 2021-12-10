// Fill out your copyright notice in the Description page of Project Settings.


#include "APGameState.h"


void AAPGameState::StartNewGame(UPlayerGameHud* HUD)
{
	Alive = true;
	PlayerScore = 0;
	
	if (IsValid(HUD))
	{
		PlayerHUD = HUD;
		PlayerHUD->SetScore(PlayerScore);	
	}
}

void AAPGameState::AddScore(int AdditionalScore)
{
	PlayerScore += AdditionalScore;
	PlayerHUD->SetScore(PlayerScore);
}
