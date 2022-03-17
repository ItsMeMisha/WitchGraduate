// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "EnemyAIController.generated.h"

/**
 * 
 */
UCLASS()
class WITCHGRADUATE_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	virtual void Tick(float DeltaSeconds) override;
	virtual void BeginPlay() override;

	virtual void OnPossess(APawn* InPawn) override;

private:
	UBehaviorTree* behaviorTree;
//	FScriptDelegate SpotEnemyDelegate;

protected:
	UFUNCTION()
	void OnSpotEnemy(AActor* Actor, FAIStimulus Stimulus);

	UPROPERTY(VisibleAnywhere, Category = AI)
	UAISenseConfig_Sight* sightConfig;

};
