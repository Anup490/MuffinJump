// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseMenuWidget.h"


void UBaseMenuWidget::SetCallback(void (start)(void)) {
	fpOnStart = start;
}

void UBaseMenuWidget::OnStart() {
	if (fpOnStart) {
		fpOnStart();
	}
}