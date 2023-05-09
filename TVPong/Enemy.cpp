// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "PongPlayer.h"
#include "PongBall.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Kismet/KismetMathLibrary.h"



// Sets default values
AEnemy::AEnemy()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

}

void AEnemy::Move()
{
	auto ActorLocation = GetActorLocation();

	if (BallLocation.X > 435.f)
		BallLocation.X = 435.f;

	if (BallLocation.X < -435.f)
		BallLocation.X = -435.f;

	FVector newLocation(BallLocation.X, ActorLocation.Y, ActorLocation.Z);

	auto ActorRotation = GetActorRotation();

	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;

	TEnumAsByte<EMoveComponentAction::Type> MoveAction = EMoveComponentAction::Move;

	UKismetSystemLibrary::MoveComponentTo(Mesh, newLocation, ActorRotation, false, false, 0.2f, true, MoveAction, LatentInfo);
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TSubclassOf<APongBall> WorldClassObject = APongBall::StaticClass();

	auto Ball = UGameplayStatics::GetActorOfClass(this, WorldClassObject);

	if(Ball)
	BallLocation = Ball->GetActorLocation();

	Move();

}

