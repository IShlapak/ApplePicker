// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Apple.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Pawn.h"
#include "AppleTree.generated.h"

UCLASS()
class APPLEPICKER_API AAppleTree : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AAppleTree();
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void RedefineDirection(float DeltaTime);
	void TrySpawnApple(float DeltaTime);

	UFUNCTION()
	void OnTreeBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


public:

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* CrownMesh;

	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* TrunkMesh;

	UPROPERTY(EditAnywhere)
	USceneComponent* AppleSpawnPlace;

	UPROPERTY(EditAnywhere)
	float Speed;

	UPROPERTY(EditAnywhere)
	float ChangeDirectionInterval;

	UPROPERTY()
	float LeftTimeToChangeDirection;

	UPROPERTY(EditAnywhere)
	float SpawnAppleInterval;

	UPROPERTY()
	float LeftTimeToSpawnApple;

	UPROPERTY(EditAnywhere)
	float ChanceOfDirectionChange;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AApple> AppleClass;

};
