// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseCloud.h"

// Sets default values
ABaseCloud::ABaseCloud()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UBoxComponent>("Box");
	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	StaticMesh->SetupAttachment(Box);
	Box->SetGenerateOverlapEvents(true);
	Box->OnComponentBeginOverlap.AddDynamic(this, &ABaseCloud::onOverlapBegin);
}

// Called when the game starts or when spawned
void ABaseCloud::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseCloud::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABaseCloud::onOverlapBegin(
	class UPrimitiveComponent* OverlappedComp,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult
) {
	float PawnZ = OtherActor->GetActorLocation().Z;
	float CloudZ = GetActorLocation().Z;
	FVector JumpVector;
	JumpVector = FVector(0, 0, 1) * JUMP_MULTIPLIER * ((PawnZ > CloudZ)?2:1);
	OtherComp->AddImpulse(JumpVector);
	Destroy();
}

