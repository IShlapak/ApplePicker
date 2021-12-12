// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ApplePicker/MainPlayerController.h"
#include "ApplePicker/UI/PlayerGameHud.h"
#include "GameFramework/Pawn.h"
#include "APPlayer.generated.h"

UCLASS()
class APPLEPICKER_API AAPPlayer : public APawn
{
	GENERATED_BODY()

	friend AMainPlayerController;
	
public:
	// Sets default values for this pawn's properties
	AAPPlayer();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void StartNewGame();

	UFUNCTION()
	void LoseLive();

	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void MoveByController(float Axis);

	UFUNCTION()
	void OnBasketMeshBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:	
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* BasketMesh;

	TSubclassOf<class UPlayerGameHud> InGameHUDClass;
	
	UPROPERTY()
	UPlayerGameHud* PlayerHUD;

	UPROPERTY()
	int PlayerLives;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Movement")
	float MaxSpeed;

};
