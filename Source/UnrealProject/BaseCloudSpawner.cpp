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

void ABaseCloudSpawner::SpawnCloudOnPlayerOverlap(UClass* pClazz, AActor* Pawn) {
	if (GEngine!=nullptr) {
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlapped with Trigger Area"));
	}
	if (Cast<ABasePlayer>(Pawn) != nullptr) {
		SpawnCloud(pClazz);
	}
}


void ABaseCloudSpawner::SpawnCloud(UClass* pClazz) {
	for (int i = 0; i < NUMBER_OF_CLOUDS_TO_SPAWN; i++) {
		Spawn(pClazz);
	}
}

void ABaseCloudSpawner::Spawn(UClass* pClazz) {
	FVector LocationVector = SpawnBox->GetComponentLocation();
	FRotator RotationVector(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	GetWorld()->SpawnActor<ABaseCloud>(pClazz, LocationVector, RotationVector, SpawnInfo);
	MoveUpwards();
}

void ABaseCloudSpawner::MoveUpwards() {
	FVector NewLocationVector = FVector(0, 0, 1) * CLOUD_SPAWNER_OFFSET;
	Root->AddLocalOffset(NewLocationVector);
}

