// Fill out your copyright notice in the Description page of Project Settings.


#include "Apple.h"

#include "APPlayer.h"
#include "Components/SphereComponent.h"
#include "GameFramework/KillZVolume.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AApple::AApple()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("root");
	RootComponent = SphereComponent;
	AppleMesh = CreateDefaultSubobject<UStaticMeshComponent>("AppleMesh");
	AppleMesh->SetupAttachment(RootComponent);

	AppleMesh->SetSimulatePhysics(true);
	AppleMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &AApple::OnAppleBeginOverlap);
}

// Called when the game starts or when spawned
void AApple::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AApple::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AApple::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AApple::OnAppleBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(Cast<AKillZVolume>(OtherActor)))
	{
		Cast<AAPPlayer> (UGameplayStatics::GetPlayerPawn(this, 0))->LoseLive();
		GetWorld()->DestroyActor(this);
	}
}

