// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerGameHud.h"

void UPlayerGameHud::NativeConstruct()
{
	Super::NativeConstruct();
	SetScore(0);
	SetHP(0);
}

void UPlayerGameHud::SetScore(int Score)
{
	if (Score < 0)
		return;

	TextScore->SetText(FText::AsNumber(Score));
}

void UPlayerGameHud::SetHP(int HP)
{
	if (HP < 0)
		return;

	TextHP->SetText(FText::AsNumber(HP));
}
