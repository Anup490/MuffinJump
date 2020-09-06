// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCamera.h"

// Sets default values
ABaseCamera::ABaseCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
}

// Called when the game starts or when spawned
void ABaseCamera::BeginPlay()
{
	Super::BeginPlay();
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this,0);
	PlayerController->SetViewTargetWithBlend(this);	
}

// Called every frame
void ABaseCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AActor* pBasePlayer = UUnrealGameInstance::GetBasePlayer();
	if (pBasePlayer != nullptr) {
		float fPawnZ = pBasePlayer->GetActorLocation().Z;
		float fCameraZ = GetActorLocation().Z;
		FVector CameraVector = FVector(0, 0, 1) * (fPawnZ - fCameraZ);
		AddActorLocalOffset(CameraVector);
	}
}

