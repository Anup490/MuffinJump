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
#include "BaseCloud.h"
#include "BaseMenuWidget.h"
#include "BaseScoreWidget.h"

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
	UBaseMenuWidget* Menu;
	UBaseScoreWidget* Score;

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
	UParticleSystemComponent* ParticleSystem;

	UFUNCTION(BlueprintCallable)
	void ExplodeMuffin(UParticleSystem* ParticleTemplate);

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
	void CreateAndShowUI(TSubclassOf<UUserWidget> UserWidgetClass);

	UFUNCTION(BlueprintCallable)
	void CreateScoreUI(TSubclassOf<UUserWidget> UserWidgetClass);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ShowUI();
	void ShowScoreUI(bool show);
public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveLeftRight(float scale);
	void Jump();
	
};
