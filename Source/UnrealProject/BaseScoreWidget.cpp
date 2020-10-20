// Fill out your copyright notice in the Description page of Project Settings.
#include "BaseScoreWidget.h"
#include "Components/TextBlock.h"

void UBaseScoreWidget::SetScoreTextBlock(UTextBlock* TextBlock) 
{
	Score = TextBlock;
}

void UBaseScoreWidget::ResetScore() 
{
	SetScore(0);
}

void UBaseScoreWidget::SetScore(int score) 
{
	if (Score) 
	{
		Score->SetText(FText::AsNumber(score));
	}
}