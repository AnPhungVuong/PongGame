// Fill out your copyright notice in the Description page of Project Settings.


#include "ScoreRight.h"
#include "Components/BoxComponent.h"
#include "PongBall.h"
#include "PongGameStateBase.h"


// Sets default values
AScoreRight::AScoreRight()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScoreRightTrigger = CreateDefaultSubobject<UBoxComponent>(TEXT("ScoreRightTrigger"));


	
}

// Called when the game starts or when spawned
void AScoreRight::BeginPlay()
{
	Super::BeginPlay();

	ScoreRightTrigger->OnComponentBeginOverlap.AddDynamic(this, &AScoreRight::EnemyLost);


	if(GameState == nullptr)
	GameState = Cast<APongGameStateBase>(GetWorld()->GetGameState());

	if (GameState)
		GameStateValid = true;
	else
		GameStateValid = false;
	
}

// Called every frame
void AScoreRight::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AScoreRight::EnemyLost(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AActor* Ball = Cast<APongBall>(OtherActor);

	if (Ball)
	{
		Ball->Destroy();
	}

	if (GameStateValid)
	{
		GameState->ThereIsABall = false;
		GameState->PlayerScore += 1;
	}
}

