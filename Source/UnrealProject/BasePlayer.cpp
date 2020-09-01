// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	SkeletalMesh->SetupAttachment(Capsule);
	Capsule->SetGenerateOverlapEvents(true);
	Capsule->OnComponentBeginOverlap.AddDynamic(this,&ABasePlayer::OnOverlapBegin);
	Capsule->OnComponentEndOverlap.AddDynamic(this,&ABasePlayer::OnOverlapEnd);
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ABasePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveLeftRight", this, &ABasePlayer::MoveLeftRight);
}

void ABasePlayer::MoveLeftRight(float scale) 
{
	if (((scale > 0) && (bShouldMoveRight)) || ((scale < 0) && (bShouldMoveLeft)))  {
		FVector moveVector = FVector(0, 1, 0) * scale * 5;
		Capsule->AddLocalOffset(moveVector);
	}
}

void ABasePlayer::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex,
	bool bFromSweep,
	const FHitResult& SweepResult) 
{
	float fBlockY = OtherActor->GetActorLocation().Y;
	float fPawnY = GetActorLocation().Y;
	if (fBlockY > fPawnY) {
		bShouldMoveRight = false;
	}
	else if (fBlockY < fPawnY) {
		bShouldMoveLeft = false;
	}
	/*
	UE_LOG(LogTemp, Warning, TEXT("Overlapped"), fPawnY);
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Overlapped"));
	*/
}

void ABasePlayer::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp,
	class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex) 
{
	bShouldMoveRight = true;
	bShouldMoveLeft = true;
}

