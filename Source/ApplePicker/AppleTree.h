// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ApplePickerGameModeBase.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "GameFramework/MovementComponent.h"
#include "AppleTree.generated.h"

UCLASS()
class APPLEPICKER_API AAppleTree : public APawn
{
	GENERATED_BODY()

	enum Direction
	{
		Right,
		Left,
	};
	
public:
	// Sets default values for this pawn's properties
	AAppleTree();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ProcessDirectionChanges(float DeltaTime);

	AApplePickerGameModeBase* GameMode;
		
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Trunk;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Crown;

	UPROPERTY(EditAnywhere)
	UFloatingPawnMovement* MovementComponent;

	Direction TreeDirection = Direction::Right;
	float ChangeDirectionInterval = 1.f;
	float LeftToChangeDirection;

};
