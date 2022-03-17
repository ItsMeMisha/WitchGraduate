// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Movement
	GetCharacterMovement()->MaxWalkSpeed = 120.0f;
	GetCharacterMovement()->bOrientRotationToMovement = true; // Rotate character to moving direction

	//My code for skeletal mesh 
	VisualMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	VisualMesh->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<USkeletalMesh> ManVisualAsset(TEXT("SkeletalMesh'/Game/Mannequin/Character/Mesh/Test_Enemy.Test_Enemy'"));

	if (ManVisualAsset.Succeeded())
	{
		VisualMesh->SetSkeletalMesh(ManVisualAsset.Object);
		VisualMesh->SetRelativeLocation(FVector(0.0f, 0.0f, -95.5f));
		VisualMesh->SetRelativeRotation(FRotator(0.0f, -90.0f, 0.0f));
	}

	Hp = 1;

	ConstructorHelpers::FObjectFinder<UAnimBlueprint> AnimObj(TEXT("AnimBlueprint'/Game/Animations/Example.Example'"));
	VisualMesh->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	VisualMesh->SetAnimInstanceClass(AnimObj.Object->GeneratedClass);

	//Rotation
	bUseControllerRotationYaw = true;

//	control->Possess(Cast<APawn>(this));
}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("Enemy %p begins play"), this);
	AController* oldController = GetController();
	UE_LOG(LogTemp, Warning, TEXT("OldController %p"), oldController);
	if (oldController) {
		oldController->UnPossess();
	}

	AController* NewController = NewObject<AEnemyAIController>(this, TEXT("Controller"));
	if (UWorld* world = GetWorld()) {
		world->AddController(NewController);
	}
	UE_LOG(LogTemp, Warning, TEXT("New Controller %p"), NewController);
	if (NewController) {
		NewController->Possess(Cast<APawn>(this));
	}
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Hp <= 0) {
		Destroy();
	}


}
/*
// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
*/

void AEnemy::UpdateWalkSpeed(float NewWalkSpeed) {

}