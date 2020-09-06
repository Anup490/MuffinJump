// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePlayer.h"

// Sets default values
ABasePlayer::ABasePlayer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	bIsFirstInput = false;
	iOldScale = 0;
	Rotation = FRotator(0, 0, 0);
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
	APlayerController* PlayerController = UGameplayStatics::GetPlayerController(this, 0);
	int iScale = (int)scale;
	if (iScale != 0) {
		if (bIsFirstInput) {
			if (iScale > 0) {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, -90, 0)));
			}
			else {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, 90, 0)));
			}
			bIsFirstInput = false;
		}
		else if((iScale != 0) && (iOldScale != iScale)){
			if (iScale > 0) {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, -180, 0)));
			}
			else {
				PlayerController->SetControlRotation(AddRotation(FRotator(0, 180, 0)));
			}
		}
		FVector MovementVector(0, MOVEMENT_MULTIPLIER, 0);
		AddMovementInput(MovementVector, scale, false);
	}
	iOldScale = iScale;
}

void ABasePlayer::Jump() 
{
	FVector JumpVector(0, 0, JUMP_MULTIPLIER);
	LaunchCharacter(JumpVector,false,true);
}

FRotator ABasePlayer::AddRotation(FRotator&& RotationOffset) {
	Rotation = Rotation + RotationOffset;
	return Rotation;
}