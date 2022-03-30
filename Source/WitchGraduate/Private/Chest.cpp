// Fill out your copyright notice in the Description page of Project Settings.


#include "Chest.h"
#include "../WitchGraduatePlayerController.h"

// Sets default values
AChest::AChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Mesh
	if (!chestMesh) {
		chestMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
		chestMesh->SetupAttachment(RootComponent);

		static ConstructorHelpers::FObjectFinder<USkeletalMesh>Mesh(TEXT("SkeletalMesh'/Game/Blender/chest.chest'"));
		if (Mesh.Succeeded()) {
			chestMesh->SetSkeletalMesh(Mesh.Object);
			chestMesh->SetWorldScale3D(FVector(0.4f, 0.4f, 0.4f));
		}
	}

	// Inventory component
	Inventory = CreateDefaultSubobject<UInventoryComponent>(TEXT("InventoryComponent"));
	Lock = CreateDefaultSubobject<ULockComponent>(TEXT("LockComponent"));
}

// Called when the game starts or when spawned
void AChest::BeginPlay()
{
	Super::BeginPlay();
	OnBeginCursorOver.AddDynamic(this, &AChest::OnCursorOverBegin);
	OnEndCursorOver.AddDynamic(this, &AChest::OnCursorOverEnd);
	
}

// Called every frame
void AChest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

UInventoryComponent* AChest::Open(UItem* Unlocker) {

	if (Unlocker) {
		if (Lock->TryUnlock(Unlocker->UnlockerType)) {
			return Inventory;
		}
		else {
			return nullptr;
		}
	}
	return nullptr;
}

void AChest::OnCursorOverBegin(AActor* TouchedActor) {
	UWorld* world = GetWorld();
	if (world) {
		AWitchGraduatePlayerController* controller = Cast<AWitchGraduatePlayerController>(world->GetFirstPlayerController());
		if (controller) {
			controller->cursorState = AWitchGraduatePlayerController::ECursorState::OnChest;
			controller->actorUnderCursor = TouchedActor;
		}
	}
}

void AChest::OnCursorOverEnd(AActor* TouchedActor) {
	UWorld* world = GetWorld();
	if (world) {
		AWitchGraduatePlayerController* controller = Cast<AWitchGraduatePlayerController>(world->GetFirstPlayerController());
		if (controller) {
			controller->cursorState = AWitchGraduatePlayerController::ECursorState::OnField;
			controller->actorUnderCursor = nullptr;
		}
	}
}