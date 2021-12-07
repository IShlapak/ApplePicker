// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"
#include "Kismet/GameplayStatics.h"
#include "Math/UnrealMathUtility.h"

// Sets default values
AAppleTree::AAppleTree()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	
	Trunk = CreateDefaultSubobject<UStaticMeshComponent>("Trunk");
	Crown = CreateDefaultSubobject<UStaticMeshComponent>("Crown");;

	Trunk->SetupAttachment(RootComponent);
	Crown->SetupAttachment(RootComponent);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("Movement");
	LeftToChangeDirection = ChangeDirectionInterval;
}

// Called when the game starts or when spawned
void AAppleTree::BeginPlay()
{
	Super::BeginPlay();
	GameMode = Cast<AApplePickerGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
}

void AAppleTree::ProcessDirectionChanges(float DeltaTime)
{
	LeftToChangeDirection -= DeltaTime;
	if (LeftToChangeDirection < 0.f)
	{
		LeftToChangeDirection = ChangeDirectionInterval;

		if (FMath::RandRange(0.f, 1.f) < GameMode->ChanceOfDirectionChange)
		{
			TreeDirection = TreeDirection == Right ? Left : Right;
		}
	}
	
	FVector direction = TreeDirection == Right ? GetActorRightVector() : GetActorRightVector() * -1.0; 
	AddMovementInput(direction, DeltaTime * GameMode->TreeMaxSpeed);
	
}

// Called every frame
void AAppleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ProcessDirectionChanges(DeltaTime);
}

