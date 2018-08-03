// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsSpawner.h"


// Sets default values
ABoidsSpawner::ABoidsSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

// Called when the game starts or when spawned
void ABoidsSpawner::BeginPlay()
{
	Super::BeginPlay();
	
	UE_LOG(LogTemp, Display, TEXT("Spawner created"));

}

// Called every frame
void ABoidsSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (m_pActorType != nullptr)
	{
		m_nTimeSinceSpawn += DeltaTime;

		if (m_nTimeSinceSpawn > m_nTimeBetweenActor && m_aActors.Num() < m_nTotalActors)
		{
			CreateActor();
			SetActorLocation(FVector(m_aActors.Num()*100.f, 0.f* m_aActors.Num()*100.f, 100.f));
			m_nTimeSinceSpawn = 0;
		}
	}

	for (int i = 0; i < m_aActors.Num(); i++)
	{
		if (absoluteCoordinates)
			m_aActors[i]->SetActorLocation(FVector(FMath::Sin(m_nTimeSinceSpawn)*i*300.f, FMath::Cos(m_nTimeSinceSpawn)*i*300.f, i*10.f));
		else
		{
			FVector currLocation = m_aActors[i]->GetActorLocation();
			FVector advanceDirection = FVector(-10.f, 10.f, 1);
			m_aActors[i]->SetActorLocation(currLocation+advanceDirection);
		}

	}
}

void ABoidsSpawner::CreateActor()
{
	ABoidsActor* pActor = GetWorld()->SpawnActor<ABoidsActor>(m_pActorType);
	m_aActors.Add(pActor);
}

