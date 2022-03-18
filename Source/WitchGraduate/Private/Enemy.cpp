// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "EnemyAIController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Perception/PawnSensingComponent.h"


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

    AIControllerClass = AEnemyAIController::StaticClass();
//	control->Possess(Cast<APawn>(this));

    //Behavior tree init
    behTree = Cast<UBehaviorTree>(StaticLoadObject(UBehaviorTree::StaticClass(), nullptr, TEXT("BehaviorTree'/Game/AI/BasicEnemyAI.BasicEnemyAI'")));
    if (behTree) {
        UE_LOG(LogTemp, Warning, TEXT("BT Found"));
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("BT NOT FOUND"));
    }

    //BlackBoard init
    blackbrd = Cast<UBlackboardData>(StaticLoadObject(UBlackboardData::StaticClass(), nullptr, (TEXT("BlackboardData'/Game/AI/BB_BasicEnemyAI.BB_BasicEnemyAI'"))));
    if (blackbrd) {
        UE_LOG(LogTemp, Warning, TEXT("BB Found"));
    }
    else {
        UE_LOG(LogTemp, Error, TEXT("BB NOT FOUND"));
    }

    //Sensing

    PawnSensingComp = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensingComp"));
    PawnSensingComp->SetPeripheralVisionAngle(60.0f);
    PawnSensingComp->SightRadius = 2000;
    PawnSensingComp->HearingThreshold = 600;
    PawnSensingComp->LOSHearingThreshold = 1200;


}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{


    if (PawnSensingComp)
    {
        PawnSensingComp->OnSeePawn.AddDynamic(this, &AEnemy::OnSpotEnemy);
    }


    UE_LOG(LogTemp, Warning, TEXT("Enemy %p begins play"), this);

    Super::BeginPlay();
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
    GetCharacterMovement()->MaxWalkSpeed = NewWalkSpeed;
}


void AEnemy::OnSpotEnemy(APawn* Pawn) {
    UE_LOG(LogTemp, Warning, TEXT("OnSpotEnemy called"));
    if (AActor* Actor = Cast<AActor>(Pawn)) {
        AEnemyAIController* controller = Cast<AEnemyAIController>(GetController());
        if (controller) {
            controller->OnSpotEnemy(Actor);
        }
    }
}