// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Character.h"
#include "Components/BoxComponent.h"
#include "Constants.h"
#include "Kismet/GameplayStatics.h"

#include "BaseCloud.generated.h"

UCLASS()
class UNREALPROJECT_API ABaseCloud : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseCloud();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void onOverlap(AActor* OtherActor, USoundBase* Sound);

public:	
	// Called every frame
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	UBoxComponent* Box;

	virtual void Tick(float DeltaTime) override;

};
