// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "Components/CapsuleComponent.h"
#include "UnrealGameInstance.h"
#include "Constants.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

#include "BasePlayer.generated.h"

UCLASS()
class UNREALPROJECT_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

	bool bWasFalling;
	bool bIsFirstInput;
	int iOldScale;
	FRotator Rotation;
	APlayerController* PlayerController;

	void GlowFireOnJump();
	void AttachFireToMuffin();
	void RotatePlayer(int iScale);
	FRotator AddRotation(FRotator&& RotationOffset);

public:
	// Sets default values for this pawn's properties
	ABasePlayer();

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UParticleSystemComponent* ParticleSystem;

	UFUNCTION(BlueprintCallable)
	void ExplodeMuffin(UParticleSystem* ParticleTemplate);
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveLeftRight(float scale);
	void Jump();
};
