// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePlayerAnimInstance.h"

UBasePlayerAnimInstance::UBasePlayerAnimInstance() {
	fSpeed = 0.0;
}

void UBasePlayerAnimInstance::NativeUpdateAnimation(float DeltaSeconds) {
	AActor* OwningActor = GetOwningActor();
	if (OwningActor) {
		fSpeed = OwningActor->GetVelocity().Size();
	}
}

