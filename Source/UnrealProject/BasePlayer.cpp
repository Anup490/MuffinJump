// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Capsule = CreateDefaultSubobject<UCapsuleComponent>("Capsule");
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	PawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("Pawn Movement");
	SkeletalMesh->SetupAttachment(Capsule);
	Capsule->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ABasePlayer::BeginPlay()
{
	Super::BeginPlay();
	UUnrealGameInstance::SaveBasePlayer(this);
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
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ABasePlayer::Jump);
}

void ABasePlayer::MoveLeftRight(float scale)
{
	FVector MovementVector(0, MOVEMENT_MULTIPLIER, 0);
	AddMovementInput(MovementVector, scale, false);
}

void ABasePlayer::Jump() 
{
	if (bShouldJump) {
		FVector JumpVector = FVector(0, 0, 1) * JUMP_MULTIPLIER;
		Capsule->AddImpulse(JumpVector);
		bShouldJump = false;
		GetWorldTimerManager().SetTimer(JumpTimerHandle, this, &ABasePlayer::DisableJump, 1.0f, true, 0.1f);
	}
}

void ABasePlayer::DisableJump() {
	iTimerJump++;
	if (iTimerJump > JUMP_TIMER) {
		iTimerJump = 0;
		bShouldJump = true;
		GetWorldTimerManager().ClearTimer(JumpTimerHandle);
	}
}