// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "BaseScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UBaseScoreWidget : public UUserWidget
{
	GENERATED_BODY()

	class UTextBlock* Score;
protected:
	UFUNCTION(BlueprintCallable)
	void SetScoreTextBlock(UTextBlock* TextBlock);
public:
	UFUNCTION(BlueprintCallable)
	void ResetScore();

	UFUNCTION(BlueprintCallable)
	void SetScore(int score);
};