// Fill out your copyright notice in the Description page of Project Settings.
#include "BasePlayerAnimInstance.h"

UBasePlayerAnimInstance::UBasePlayerAnimInstance() 
{
	fSpeed = 0.0;
	bIsJumping = false;
	bIsFalling = false;
}

void UBasePlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds) 
{
	AActor* OwningActor = GetOwningActor();
	if (OwningActor) 
	{
		fSpeed = OwningActor->GetVelocity().Size();
		bIsJumping = OwningActor->GetVelocity().Z > 0;
		bIsFalling = OwningActor->GetVelocity().Z < 0;
	}
}

