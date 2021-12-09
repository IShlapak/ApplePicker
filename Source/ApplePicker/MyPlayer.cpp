// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayer.h"

#include "APGameInstance.h"
#include "Components/InputComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
AMyPlayer::AMyPlayer()
	: MaxSpeed(10.f)
	, Lives(3) 
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");

	BasketMesh = CreateDefaultSubobject<UStaticMeshComponent>("BasketMesh");
	BasketMesh->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AMyPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (UGameplayStatics::GetCurrentLevelName(GetWorld()) == FString("Main"))
	{
		PlayerHUD = CreateDefaultSubobject<UPlayerGameHud>("GameHud");
		PlayerHUD->AddToViewport();
		PlayerHUD->SetHP(Lives);
//TODO
		//Cast<BP_GameState>(GetWorld()->GetGameState());

		PlayerHUD->SetScore(0);
	}
	
}

// Called every frame
void AMyPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyPlayer::LoseLife()
{
	Lives -= 1;
	PlayerHUD->SetHP(Lives);

	if (Lives <= 0)
	{
// TODO		
//		GetGameState() set Alive - false
		Cast<UAPGameInstance>(GetGameInstance())->GameOver();
	}
}

