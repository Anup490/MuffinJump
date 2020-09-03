// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCloudSpawner.h"

// Sets default values
ABaseCloudSpawner::ABaseCloudSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>("Default Root");
	TriggerBox = CreateDefaultSubobject<UBoxComponent>("Trigger Box");
	SpawnBox = CreateDefaultSubobject<UBoxComponent>("Spawn Box");
}

// Called when the game starts or when spawned
void ABaseCloudSpawner::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABaseCloudSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCloudSpawner::SpawnCloud(UClass* pClazz) {
	FVector SpawnerLocationVector = GetActorLocation();
	FRotator RotationVector(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<ABaseCloud>(pClazz,SpawnerLocationVector, RotationVector, SpawnInfo);
}

