// Fill out your copyright notice in the Description page of Project Settings.


#include "PongPlayer.h"
#include "Components/StaticMeshComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"


// Sets default values
APongPlayer::APongPlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Speed = 8.0f;


	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

}


void APongPlayer::MoveUp()
{
	
	MoveVector = FVector(Speed, 0, 0);


	MovingUp = true;

	

}

void APongPlayer::MoveDown()
{

	MoveVector = FVector(-1.0f *Speed, 0, 0);

	

	MovingDown = true;

	
}

void APongPlayer::StopMovingUp()
{
	MovingUp = false;
}

void APongPlayer::StopMovingDown()
{
	MovingDown = false;
}

// Called when the game starts or when spawned
void APongPlayer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APongPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	

	auto CurrentLocation = GetActorLocation();

	auto Destination = CurrentLocation + MoveVector;
	
	if (Destination.X >= 435)
		Destination.X = 435;

	if (Destination.X <= -435)
		Destination.X = -435;


	if (MovingUp || MovingDown)
	SetActorLocation(Destination);



}

// Called to bind functionality to input
void APongPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("MoveUp", IE_Pressed, this, &APongPlayer::MoveUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Pressed, this, &APongPlayer::MoveDown);


	PlayerInputComponent->BindAction("MoveUp", IE_Released, this, &APongPlayer::StopMovingUp);
	PlayerInputComponent->BindAction("MoveDown", IE_Released, this, &APongPlayer::StopMovingDown);
}

