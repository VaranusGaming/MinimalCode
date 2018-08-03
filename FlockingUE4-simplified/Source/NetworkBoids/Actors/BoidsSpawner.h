// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/Actor.h"
#include "BoidsActor.h"
#include "BoidsSpawner.generated.h"

UCLASS()
class NETWORKBOIDS_API ABoidsSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoidsSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
		TSubclassOf<ABoidsActor> m_pActorType;

private:
	TArray<ABoidsActor*> m_aActors;

	UPROPERTY(EditDefaultsOnly)
//		float m_nTotalActors = 200;
	float m_nTotalActors = 10;

	UPROPERTY(EditDefaultsOnly)
		float m_nTimeBetweenActor = 0.1f;

	float m_nTimeSinceSpawn;

	bool absoluteCoordinates = false;

	void CreateActor();
};
