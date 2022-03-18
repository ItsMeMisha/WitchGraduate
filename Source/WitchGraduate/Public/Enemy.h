// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "Enemy.generated.h"

UCLASS()
class WITCHGRADUATE_API AEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Mesh*/
	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* VisualMesh;
public:
	UPROPERTY(VisibleAnywhere)
		int32 Hp;

	UFUNCTION(BlueprintCallable, Category = Movement)
	void UpdateWalkSpeed(float NewWalkSpeed);


	UBehaviorTree* behTree;
	UBlackboardData* blackbrd;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UPawnSensingComponent* PawnSensingComp;

	UFUNCTION()
	void OnSpotEnemy(APawn* Pawn);
};
