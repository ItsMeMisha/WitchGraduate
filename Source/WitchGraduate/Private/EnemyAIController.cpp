// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"

#include "Enemy.h"
#include "Perception/AIPerceptionComponent.h"



AEnemyAIController::AEnemyAIController() {
	bStartAILogicOnPossess = true;
	BehaviorComp = CreateDefaultSubobject<UBehaviorTreeComponent>(TEXT("BehaviorComp"));
	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(TEXT("BlackBoardComp"));
	/*
	//Behavior tree init
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> btAsset(TEXT("BehaviorTree'/Game/AI/BasicEnemyAI.BasicEnemyAI'"));
	if (btAsset.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("BT Found"));
		behaviorTree = btAsset.Object;
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("BT NOT FOUND"));
	}

	//BlackBoard init
	static ConstructorHelpers::FObjectFinder<UBlackboardData> bbAsset(TEXT("BlackboardData'/Game/AI/BB_BasicEnemyAI.BB_BasicEnemyAI'"));
	if (bbAsset.Succeeded()) {
		UE_LOG(LogTemp, Warning, TEXT("BB Found"));
		if (UseBlackboard(bbAsset.Object, Blackboard)) {
			UE_LOG(LogTemp, Warning, TEXT("BB Connected"));
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("BB NOT CONNECTED"));
		}
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("BB NOT FOUND"));
	}
	*/

}

void AEnemyAIController::BeginPlay() {

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay enemy controller"));

	Super::BeginPlay();

}

void AEnemyAIController::Tick(float DeltaSeconds) {
	Super::Tick(DeltaSeconds);
	//UE_LOG(LogTemp, Warning, TEXT("Tick"));
//	APawn* pawn = GetPawn();
	//if (pawn) {
		//UE_LOG(LogTemp, Warning, TEXT("Has Pawn"));
	//	FVector pos = pawn->GetActorLocation();
//		pos += FVector{ 10, 0, 0 };
		//pawn->SetActorLocation(pos);
	//}
}

void AEnemyAIController::OnPossess(APawn* InPawn) {

	UE_LOG(LogTemp, Warning, TEXT("Trying to possess pawn %p"), InPawn);
	Super::OnPossess(InPawn);

	AEnemy* pawn = Cast<AEnemy>(InPawn);
	if (pawn) {
		if (pawn->behTree) {
			behaviorTree = pawn->behTree;
		}
		if (behaviorTree->BlackboardAsset && BlackboardComp->InitializeBlackboard(*(behaviorTree->BlackboardAsset))) {
			UE_LOG(LogTemp, Warning, TEXT("BB Connected"));
		}
		else {
			UE_LOG(LogTemp, Error, TEXT("BB NOT CONNECTED"));
		}
	}

	RunBehaviorTree(behaviorTree);
}

void AEnemyAIController::OnSpotEnemy(AActor* Actor) {
	UE_LOG(LogTemp, Warning, TEXT("OnSpotEnemy controller called"));
	if (Actor->ActorHasTag(FName(TEXT("Player")))) {
		BlackboardComp->SetValueAsBool(FName(TEXT("HasLineOfSight")), true);
		BlackboardComp->SetValueAsObject(FName(TEXT("EnemyActor")), Actor);
		UE_LOG(LogTemp, Warning, TEXT("Spotted"));
	}
	else {
		BlackboardComp->SetValueAsBool(FName(TEXT("HasLineOfSight")), false);
		BlackboardComp->SetValueAsObject(FName(TEXT("EnemyActor")), nullptr);
	}
}

