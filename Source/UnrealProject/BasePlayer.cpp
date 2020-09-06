// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsFirstInput = true;
	iOldScale = 0;
	Rotation = FRotator(0, 0, 0);
	PlayerController = UGameplayStatics::GetPlayerController(this, 0);
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
	int iScale = (int)scale;
	if (iScale != 0) {
		RotatePlayer(iScale);
		FVector MovementVector(0, MOVEMENT_MULTIPLIER, 0);
		AddMovementInput(MovementVector, scale, false);
	}
}

void ABasePlayer::Jump() 
{
	FVector JumpVector(0, 0, JUMP_MULTIPLIER);
	LaunchCharacter(JumpVector,false,true);
}

void ABasePlayer::RotatePlayer(int iScale) {
	if (iOldScale != iScale) {
		iOldScale = iScale;
		if (bIsFirstInput) {
			if (iScale > 0) {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, 180 * iScale, 0)));
			}
			else {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, 360 * iScale, 0)));
			}
			bIsFirstInput = false;
		}
		PlayerController->SetControlRotation(AddRotation(FRotator(0, 180 * iScale, 0)));
	}
}

FRotator ABasePlayer::AddRotation(FRotator&& RotationOffset) {
	Rotation = Rotation + RotationOffset;
	return Rotation;
}