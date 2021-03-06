// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseCloud.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Components/AudioComponent.h"
#include "Constants.h"
#include "BaseCamera.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseCloud::ABaseCloud()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RainMesh = CreateDefaultSubobject<UStaticMeshComponent>("Rain");
	Audio = CreateDefaultSubobject<UAudioComponent>("Audio");
	StaticMesh->SetupAttachment(Box);
	RainMesh->SetupAttachment(StaticMesh);
	Box->SetGenerateOverlapEvents(true);
}

// Called when the game starts or when spawned
void ABaseCloud::BeginPlay()
{
	Super::BeginPlay();
	RainMesh->SetVisibility(false);
}

// Called every frame
void ABaseCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseCloud::EnableRain() 
{
	RainMesh->SetVisibility(true);
	Audio->Activate();
}

void ABaseCloud::onOverlap(AActor* OtherActor, USoundBase* Sound) 
{
	ACharacter* Player = Cast<ACharacter>(OtherActor);
	if (Player != nullptr) 
	{
		FVector JumpVector(0, 0, JUMP_MULTIPLIER);
		Player->LaunchCharacter(JumpVector, false, true);;
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), Sound, GetActorLocation(), FRotator(0,0,0), 1, 1, 0, 0, 0, 0);
		Destroy();
	}
	else if (Cast<ABaseCamera>(OtherActor)) 
	{
		Destroy();
	}
}

