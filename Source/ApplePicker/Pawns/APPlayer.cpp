// Fill out your copyright notice in the Description page of Project Settings.


#include "APPlayer.h"

#include "Apple.h"
#include "ApplePicker/APGameInstance.h"
#include "ApplePicker/APGameState.h"
#include "ApplePicker/UI/PlayerGameHud.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AAPPlayer::AAPPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BasketMesh = CreateDefaultSubobject<UStaticMeshComponent>("BasketMesh");
	RootComponent = BasketMesh;

	static ConstructorHelpers::FClassFinder<UPlayerGameHud> InGameBPPauseClass(TEXT("/Game/Blueprints/UI/WBP_PlayerHud"));
	InGameHUDClass = InGameBPPauseClass.Class;

	BasketMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &AAPPlayer::OnBasketMeshBeginOverlap);
}

// Called when the game starts or when spawned
void AAPPlayer::BeginPlay()
{
	Super::BeginPlay();

	PlayerHUD = CreateWidget<UPlayerGameHud>(GetWorld(), InGameHUDClass);
	PlayerHUD->AddToViewport();

	AAPGameState* GameState = Cast<AAPGameState>(UGameplayStatics::GetGameState(this));
	if(IsValid(GameState))
	{
		GameState->StartNewGame(PlayerHUD);
	}

	StartNewGame();
}

void AAPPlayer::MoveByController(float Axis)
{
	FVector DeltaLocation = MaxSpeed * Axis * GetActorRightVector();
	AddActorWorldOffset(DeltaLocation, true);
}

// Called every frame
void AAPPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAPPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AAPPlayer::StartNewGame()
{
	PlayerLives = 3;
	PlayerHUD->SetHP(PlayerLives);
}

void AAPPlayer::LoseLive()
{
	PlayerLives -= 1;
	PlayerHUD->SetHP(PlayerLives);

	if (PlayerLives > 0)
		return;

	Cast<AAPGameState>(GetWorld()->GetGameState())->Alive = false;
	Cast<UAPGameInstance>(GetGameInstance())->GameOver();
}

void AAPPlayer::OnBasketMeshBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(Cast<AApple>(OtherActor)))
	{
		Cast<AAPGameState>(UGameplayStatics::GetGameState(this))->AddScore(1);
		GetWorld()->DestroyActor(OtherActor);
	}
}

