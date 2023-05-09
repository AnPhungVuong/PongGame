// Fill out your copyright notice in the Description page of Project Settings.


#include "PongGameStateBase.h"

APongGameStateBase::APongGameStateBase()
{
	ThereIsABall = true;
	PlayerScore = 0;
	EnemyScore = 0;

}

void APongGameStateBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FString ScoreMsg = FString::Printf(TEXT("Player Score :%d, Enemy Score: %d"), PlayerScore, EnemyScore);

	

	GEngine->AddOnScreenDebugMessage(1, 2, FColor::Blue,ScoreMsg);
}

