// Fill out your copyright notice in the Description page of Project Settings.

#include "BoidsActor.h"


// Sets default values
ABoidsActor::ABoidsActor()
{
	bCanBeDamaged = false;

	//Add sphere component
	static ConstructorHelpers::FObjectFinder<UStaticMesh> pMesh (TEXT("/Engine/BasicShapes/Sphere"));

	m_pSphereComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("Display Sphere"));
	m_pSphereComponent->SetStaticMesh(pMesh.Object);

	m_pSphereComponent->bOwnerNoSee = false;
	m_pSphereComponent->CastShadow = true;
	m_pSphereComponent->SetHiddenInGame(false);

	m_pSphereComponent->BodyInstance.SetCollisionEnabled(ECollisionEnabled::NoCollision);

	RootComponent = m_pSphereComponent;
}

// Called when the game starts or when spawned
void ABoidsActor::BeginPlay()
{
	Super::BeginPlay();
	
}

