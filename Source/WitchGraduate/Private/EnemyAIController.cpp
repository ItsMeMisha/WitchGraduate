// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Perception/AIPerceptionComponent.h"



AEnemyAIController::AEnemyAIController() {
	bStartAILogicOnPossess = true;

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

	/*
	SpotEnemyDelegate.BindUFunction(this, FName(TEXT("OnSpotEnemy")));
	PerceptionComponent->OnTargetPerceptionUpdated.Add(onSpotEnemyDelegate);*/
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("PerceptionComponent"));
	PerceptionComponent->RegisterComponent();
	sightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight config"));
	sightConfig->SightRadius = 500.0f;
	sightConfig->LoseSightRadius = 520.0f;
	sightConfig->PeripheralVisionAngleDegrees = 359.0f; //damn
	sightConfig->DetectionByAffiliation.bDetectEnemies = true;
	sightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	sightConfig->DetectionByAffiliation.bDetectFriendlies = true;


	UE_LOG(LogTemp, Warning, TEXT("Set sight configs"));
	UE_LOG(LogTemp, Warning, TEXT("Listener id is valid %d"), PerceptionComponent->GetListenerId().IsValid());
	UE_LOG(LogTemp, Warning, TEXT("Listener is pending kill %d"), PerceptionComponent->IsPendingKill());
	if (UWorld* world = GetWorld()) {
		UE_LOG(LogTemp, Warning, TEXT("Valid world"));
		if (UAIPerceptionSystem* percSys = UAIPerceptionSystem::GetCurrent(*world)) {
			UE_LOG(LogTemp, Warning, TEXT("Valid perception system"));
			percSys->UpdateListener(*PerceptionComponent);
			UE_LOG(LogTemp, Warning, TEXT("Listener id is valid after update %d"), PerceptionComponent->GetListenerId().IsValid());
		}
	}
	PerceptionComponent->ConfigureSense(*sightConfig);
	PerceptionComponent->SetDominantSense(sightConfig->GetSenseImplementation());

}

void AEnemyAIController::BeginPlay() {

	UE_LOG(LogTemp, Warning, TEXT("BeginPlay enemy"));
//	SpotEnemyDelegate.BindUFunction(this, FName(TEXT("OnSpotEnemy")));
	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnSpotEnemy);
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

	BeginPlay();
	if (!UAIPerceptionSystem::RegisterPerceptionStimuliSource(this, sightConfig->GetSenseImplementation(), InPawn)) {
		UE_LOG(LogTemp, Error, TEXT("Failed register stimulisource"));
	}
	//UE_LOG(LogTemp, Warning, TEXT("Set sight configs 2"));
	//PerceptionComponent->ConfigureSense(*sightConfig);
	//RunBehaviorTree(behaviorTree);
}

void AEnemyAIController::OnSpotEnemy(AActor* Actor, FAIStimulus Stimulus) {
	UE_LOG(LogTemp, Warning, TEXT("OnSpotEnemy called"));
	if (Actor->ActorHasTag(FName(TEXT("Player"))) && Stimulus.WasSuccessfullySensed()) {
		GetBlackboardComponent()->SetValueAsBool(FName(TEXT("HasLineOfSight")), true);
		GetBlackboardComponent()->SetValueAsObject(FName(TEXT("EnemyActor")), Actor);
		UE_LOG(LogTemp, Warning, TEXT("Spotted"));
	}
	else {
		GetBlackboardComponent()->SetValueAsBool(FName(TEXT("HasLineOfSight")), false);
		GetBlackboardComponent()->SetValueAsObject(FName(TEXT("EnemyActor")), nullptr);
	}
}

