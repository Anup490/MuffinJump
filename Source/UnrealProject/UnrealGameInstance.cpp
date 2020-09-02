// Fill out your copyright notice in the Description page of Project Settings.


#include "UnrealGameInstance.h"

APawn* UUnrealGameInstance::pPawn = 0;

void UUnrealGameInstance::SaveBasePlayer(APawn* pBasePlayer) {
	pPawn = pBasePlayer;
}

APawn* UUnrealGameInstance::GetBasePlayer() {
	return pPawn;
}