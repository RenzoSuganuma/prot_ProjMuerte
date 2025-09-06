// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameManager.generated.h"

UCLASS()
class PROTO_PROJMUERTE_API AGameManager : public AActor
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere)
	float m_timelimit;

	UPROPERTY(EditAnywhere)
	UWorld* m_levelTitle;

	float m_elapsed;

public:
	// Sets default values for this actor's properties
	AGameManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void Destroyed() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UFUNCTION(BlueprintCallable)
	float GetTimeLimit() const;
};
