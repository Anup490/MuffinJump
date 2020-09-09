// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

#include "BaseMenuWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UBaseMenuWidget : public UUserWidget
{
	GENERATED_BODY()

	void (*fpOnStart) (void);

protected:
	UFUNCTION(BlueprintCallable)
	void OnStart();
public:
	void SetCallback(void start(void));
};
