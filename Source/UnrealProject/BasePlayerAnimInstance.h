// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "BasePlayerAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UBasePlayerAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	float fSpeed;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsJumping;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	bool bIsFalling;

public:
	UBasePlayerAnimInstance();
	void NativeUpdateAnimation(float DeltaSeconds) override;

};
