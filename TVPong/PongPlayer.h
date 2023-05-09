// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PongPlayer.generated.h"

UCLASS()
class TVPONG_API APongPlayer : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APongPlayer();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UCameraComponent* Camera;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Speed;

	bool MovingUp;

	bool MovingDown;

	FVector MoveVector;

	void MoveUp();

	void MoveDown();

	void StopMovingUp();
	
	void StopMovingDown();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
