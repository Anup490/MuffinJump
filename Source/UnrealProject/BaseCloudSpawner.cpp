// Fill out your copyright notice in the Description page of Project Settings.

#include "BaseCloudSpawner.h"
#include "Components/BoxComponent.h"
#include "BaseCloud.h"
#include "BasePlayer.h"
#include "Constants.h"
#include "BaseCamera.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

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
	OgLocation = GetActorLocation();
	OgLocation.Z -= 690;
}

// Called every frame
void ABaseCloudSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCloudSpawner::OnReset() 
{
	SetActorLocation(OgLocation);
	TArray<AActor*> BaseClouds;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ABaseCloud::StaticClass(), BaseClouds);
	for (AActor* Actor : BaseClouds) 
	{
		ABaseCloud* Cloud = Cast<ABaseCloud>(Actor);
		if (Cloud) 
		{
			Cloud->Destroy();
		}
	}
	if (pCloud) 
	{
		SpawnCloud(pCloud);
	}
}

void ABaseCloudSpawner::SpawnCloudOnPlayerOverlap(UClass* pClazz, AActor* Pawn) 
{
	if (Cast<ABasePlayer>(Pawn) != nullptr) 
	{
		SpawnCloud(pClazz);
	}
}

void ABaseCloudSpawner::SpawnCloud(UClass* pClazz)
{
	if (pCloud == 0) 
	{
		pCloud = pClazz;
	}
	for (int i = 0; i < NUMBER_OF_CLOUDS_TO_SPAWN; i++) 
	{
		Spawn(pClazz);
	}
}

void ABaseCloudSpawner::Spawn(UClass* pClazz) 
{
	FVector LocationVector = SpawnBox->GetComponentLocation();
	LocationVector.Y = GetRandomY();
	FRotator RotationVector(0.0f, 0.0f, 0.0f);
	FActorSpawnParameters SpawnInfo;
	ABaseCloud* Cloud = GetWorld()->SpawnActor<ABaseCloud>(pClazz, LocationVector, RotationVector, SpawnInfo);
	if (ShouldRain()) 
	{
		Cloud->EnableRain();
	}
	MoveUpwards();
}

bool ABaseCloudSpawner::ShouldRain() 
{
	return FMath::RandRange(0,10) > 8;
}

float ABaseCloudSpawner::GetRandomY() 
{
	FBoxSphereBounds SpawnBoxBounds = SpawnBox->Bounds;
	FVector RandomVector = UKismetMathLibrary::RandomPointInBoundingBox(SpawnBoxBounds.Origin, SpawnBoxBounds.BoxExtent);
	return RandomVector.Y;
}

void ABaseCloudSpawner::MoveUpwards() 
{
	FVector NewLocationVector = FVector(0, 0, 1) * CLOUD_SPAWNER_OFFSET;
	Root->AddLocalOffset(NewLocationVector);
}