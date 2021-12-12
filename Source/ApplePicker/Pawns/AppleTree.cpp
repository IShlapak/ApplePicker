// Fill out your copyright notice in the Description page of Project Settings.


#include "AppleTree.h"
#include "Apple.h"
#include "ApplePicker/APGameState.h"
#include "Engine/BlockingVolume.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AAppleTree::AAppleTree()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");
	CrownMesh = CreateDefaultSubobject<UStaticMeshComponent>("Crown");
	TrunkMesh = CreateDefaultSubobject<UStaticMeshComponent>("Trunk");
	AppleSpawnPlace = CreateDefaultSubobject<USceneComponent>("AppleSpawner");

	CrownMesh->SetupAttachment(RootComponent);
	TrunkMesh->SetupAttachment(RootComponent);
	AppleSpawnPlace->SetupAttachment(CrownMesh);

	CrownMesh->OnComponentBeginOverlap.AddUniqueDynamic(this, &AAppleTree::AAppleTree::OnTreeBeginOverlap);
}

// Called when the game starts or when spawned
void AAppleTree::BeginPlay()
{
	Super::BeginPlay();
	LeftTimeToChangeDirection = ChangeDirectionInterval;
	LeftTimeToSpawnApple = SpawnAppleInterval;
}

void AAppleTree::RedefineDirection(float DeltaTime)
{
	LeftTimeToChangeDirection -= DeltaTime;

	if (LeftTimeToChangeDirection > 0.f)
		return;

	LeftTimeToChangeDirection = ChangeDirectionInterval;
	
	if (UKismetMathLibrary::RandomFloat() > ChanceOfDirectionChange)
		return;

	Speed *= -1;
	
}

void AAppleTree::TrySpawnApple(float DeltaTime)
{
	LeftTimeToSpawnApple -= DeltaTime;

	if(LeftTimeToSpawnApple > 0.f)
		return;

	FActorSpawnParameters SpawnInfo;
	SpawnInfo.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	GetWorld()->SpawnActor<AApple>(AppleClass, AppleSpawnPlace->GetComponentLocation(), FRotator(), SpawnInfo);

	LeftTimeToSpawnApple = SpawnAppleInterval;
}

void AAppleTree::OnTreeBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (IsValid(Cast<ABlockingVolume>(OtherActor)))
	{
		Speed *= -1;
	}
}

// Called every frame
void AAppleTree::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!Cast<AAPGameState>(UGameplayStatics::GetGameState(this))->Alive)
		return;

	RedefineDirection(DeltaTime);
	TrySpawnApple(DeltaTime);

	FVector DeltaLocation = GetActorRightVector() * Speed * DeltaTime; 
	AddActorWorldOffset(DeltaLocation, true);
	
}

// Called to bind functionality to input
void AAppleTree::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

