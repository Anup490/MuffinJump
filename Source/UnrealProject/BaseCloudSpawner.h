// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseCloudSpawner.generated.h"

UCLASS()
class UNREALPROJECT_API ABaseCloudSpawner : public AActor
{
	GENERATED_BODY()

	FVector OgLocation;
	UClass* pCloud = 0;
	void Spawn(UClass* pClazz);
	bool ShouldRain();
	float GetRandomY();
	void MoveUpwards();
public:	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class USceneComponent* Root;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UBoxComponent* TriggerBox;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UBoxComponent* SpawnBox;

	// Sets default values for this actor's properties
	ABaseCloudSpawner();
protected:
	UFUNCTION(BlueprintCallable)
	void SpawnCloudOnPlayerOverlap(UClass* pClazz, AActor* Actor);

	UFUNCTION(BlueprintCallable)
	void SpawnCloud(UClass* pClazz);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void OnReset();
};