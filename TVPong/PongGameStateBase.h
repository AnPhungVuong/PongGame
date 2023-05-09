// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "PongGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class TVPONG_API APongGameStateBase : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	APongGameStateBase();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool ThereIsABall;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int PlayerScore;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int EnemyScore;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
