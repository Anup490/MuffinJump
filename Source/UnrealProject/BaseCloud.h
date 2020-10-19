// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	class UAudioComponent* Audio;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* RainMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UStaticMeshComponent* StaticMesh;

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly)
	class UBoxComponent* Box;

	// Called every frame
	virtual void Tick(float DeltaTime) override;
	void EnableRain();
};
