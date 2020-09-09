// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"

#include "BaseScoreWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALPROJECT_API UBaseScoreWidget : public UUserWidget
{
	GENERATED_BODY()

	UTextBlock* Score;
protected:
	UFUNCTION(BlueprintCallable)
	void SetScoreTextBlock(UTextBlock* TextBlock);
public:
	void ResetScore();
	void SetScore(int score);
};
