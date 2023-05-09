// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ScoreRight.generated.h"

UCLASS()
class TVPONG_API AScoreRight : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AScoreRight();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UBoxComponent* ScoreRightTrigger;

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
		void EnemyLost(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

};
