// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "UnrealGameInstance.h"
#include "Constants.h"

#include "BasePlayer.generated.h"

UCLASS()
class UNREALPROJECT_API ABasePlayer : public APawn
{
	GENERATED_BODY()

	int iTimerJump = 0;
	bool bShouldJump = true;
	FTimerHandle JumpTimerHandle;
public:
	// Sets default values for this pawn's properties
	ABasePlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UCapsuleComponent* Capsule;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	USkeletalMeshComponent* SkeletalMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UFloatingPawnMovement* PawnMovement;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveLeftRight(float scale);
	void Jump();
	void DisableJump();
};
