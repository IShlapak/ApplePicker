// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"


// Sets default values
AMyPlayer::AMyPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	BasketMesh = CreateDefaultSubobject<UStaticMeshComponent>("BasketMesh");
	BasketMesh->SetupAttachment(RootComponent);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>("CollisionBox");
	CollisionBox->SetupAttachment(RootComponent);
	
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>("MovementComponent");

}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("LeftRight", this, &AMyPlayer::MoveBasket);
}

void AMyPlayer::MoveBasket(float axis)
{
	AddActorWorldOffset(GetActorRightVector() * axis * 2.0);
	//AddMovementInput(GetActorRightVector(), axis * 10.0);
}

