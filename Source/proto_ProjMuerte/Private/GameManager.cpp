// Fill out your copyright notice in the Description page of Project Settings.


#include "GameManager.h"

#include "Kismet/GameplayStatics.h"

// Sets default values
AGameManager::AGameManager() : m_elapsed(0)
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AGameManager::BeginPlay()
{
	Super::BeginPlay();
}

void AGameManager::Destroyed()
{
	Super::Destroyed();
}

// Called every frame
void AGameManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	m_elapsed += DeltaTime;

	if (m_elapsed >= m_timelimit)
	{
		UGameplayStatics::OpenLevel(this, FName(m_levelTitle->GetName()));
	}
}

float AGameManager::GetTimeLimit() const
{
	return m_timelimit - m_elapsed;
}
