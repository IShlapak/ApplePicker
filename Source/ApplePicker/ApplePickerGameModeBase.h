// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "ApplePickerGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class APPLEPICKER_API AApplePickerGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float TimeToAppleGenerate;

	UPROPERTY(EditAnywhere)
	float ChanceOfDirectionChange;

	UPROPERTY(EditAnywhere)
	float TreeMaxSpeed = 100.0;

	UPROPERTY(EditAnywhere)
	uint32 Score = 0;
	
	UPROPERTY(EditAnywhere)
	uint32 HP = 3;
	
};
