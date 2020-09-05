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
	UPROPERTY(VisibleAnywhere,BlueprintReadWrite)
	float fSpeed;
	
public:
	UBasePlayerAnimInstance();
	void NativeUpdateAnimation(float DeltaSeconds) override;

};
