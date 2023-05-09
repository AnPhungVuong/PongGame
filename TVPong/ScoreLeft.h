// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreLeft.generated.h"

UCLASS()
class TVPONG_API AScoreLeft : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreLeft();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* ScoreLeftTrigger;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class APongGameStateBase* GameState;

	bool GameStateValid;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void PlayerLost(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);



};
