// Fill out your copyright notice in the Description page of Project Settings.


#include "WallUp.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"

// Sets default values
AWallUp::AWallUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("ColliisonBox"));

	CollisionBox->SetupAttachment(Mesh);

}

// Called when the game starts or when spawned
void AWallUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWallUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

