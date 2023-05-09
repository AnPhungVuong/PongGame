// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PongBall.generated.h"

UCLASS()
class TVPONG_API APongBall : public AActor
{
	GENERATED_BODY()

public:
		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UStaticMeshComponent* Mesh;

		UPROPERTY(EditAnywhere, BlueprintReadWrite)
			class UProjectileMovementComponent* ProjectileComp;
	
public:	
	// Sets default values for this actor's properties
	APongBall();
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;


};
