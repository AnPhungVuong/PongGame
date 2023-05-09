// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreLeft.h"
#include "Components/BoxComponent.h"
#include "PongGameStateBase.h"
#include "PongBall.h"



// Sets default values
AScoreLeft::AScoreLeft()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScoreLeftTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ScoreLeftTrigger"));

	

}

// Called when the game starts or when spawned
void AScoreLeft::BeginPlay()
{
	Super::BeginPlay();

	ScoreLeftTrigger->OnComponentBeginOverlap.AddDynamic(this, &AScoreLeft::PlayerLost);


	if (GameState == nullptr)
		GameState = Cast<APongGameStateBase>(GetWorld()->GetGameState());

	if (GameState)
		GameStateValid = true;
	else
		GameStateValid = false;
	
}

// Called every frame
void AScoreLeft::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// begin overlap

void AScoreLeft::PlayerLost(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor* Ball = Cast<APongBall>(OtherActor);

	if (Ball)
	{
		Ball->Destroy();
	}

	if (GameStateValid)
	{
		GameState->ThereIsABall = false;
		GameState->EnemyScore += 1;
	}

}


