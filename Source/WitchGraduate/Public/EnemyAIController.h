// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionTypes.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
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
	UBehaviorTreeComponent* BehaviorComp;
	UBlackboardComponent* BlackboardComp;


//	FScriptDelegate SpotEnemyDelegate;

public:
	UFUNCTION()
	void OnSpotEnemy(AActor* Actor);

	UPROPERTY(VisibleAnywhere, Category = AI)
	UAISenseConfig_Sight* sightConfig;

};
