// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasePlayer.generated.h"


UCLASS()
class UNREALPROJECT_API ABasePlayer : public ACharacter
{
	GENERATED_BODY()

	static bool bShowMenu;

	bool bIsMenuHidden;
	bool bEnableControl;
	bool bIsMortal;
	bool bWasFalling;
	bool bIsFirstInput;
	int iOldScale;
	int iScore;
	FRotator Rotation;
	APlayerController* PlayerController;

	void GlowFireOnJump();
	void AttachFireToMuffin();
	void RotatePlayer(int iScale);
	FRotator AddRotation(FRotator&& RotationOffset);
	void EnableAndShowMuffin(bool showAndActivate);

public:
	// Sets default values for this pawn's properties
	ABasePlayer();
	static void onStartClick();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UParticleSystemComponent* ParticleSystem;

	UFUNCTION(BlueprintCallable)
	void ExplodeMuffin(class UParticleSystem* ParticleTemplate);

	UFUNCTION()
	void onOverlapBegin(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex,
		bool bFromSweep,
		const FHitResult& SweepResult
	);	

	UFUNCTION(BlueprintCallable)
	void RegisterCallbackAndShowUI(class UBaseMenuWidget* Menu);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowMenu(bool show);

	UFUNCTION(BlueprintImplementableEvent)
	void ShowScoreUI(bool show);

	UFUNCTION(BlueprintImplementableEvent)
	void ResetScore();

	UFUNCTION(BlueprintImplementableEvent)
	void SetScore(int iValue);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void ShowUI();
	void ResetCloudSpawner();
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveLeftRight(float scale);
	void Jump();
};
