// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"

#include "UnrealGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UUnrealGameInstance : public UGameInstance
{
	GENERATED_BODY()

	static APawn* pPawn;

public:
	static void SaveBasePlayer(APawn* pBasePlayer);
	static APawn* GetBasePlayer();
};
