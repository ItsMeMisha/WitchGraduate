// Copyright Epic Games, Inc. All Rights Reserved.

#include "WitchGraduatePlayerController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "WitchGraduateCharacter.h"
#include "Engine/World.h"
#include "Projectile.h"
#include "Chest.h"


AWitchGraduatePlayerController::AWitchGraduatePlayerController()
{
	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
	bEnableClickEvents = true;
	cursorState = OnField;
	actorUnderCursor = nullptr;
	DefaultMouseCursor = EMouseCursor::Crosshairs;
}

void AWitchGraduatePlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}
}

void AWitchGraduatePlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AWitchGraduatePlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AWitchGraduatePlayerController::OnSetDestinationReleased);

	// support touch devices 
	/*InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AWitchGraduatePlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AWitchGraduatePlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AWitchGraduatePlayerController::OnResetVR);*/

	// throwing Projectile
	InputComponent->BindAction("MainAction", IE_Pressed, this, &AWitchGraduatePlayerController::OnMainAction);
}

void AWitchGraduatePlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AWitchGraduatePlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AWitchGraduateCharacter* MyPawn = Cast<AWitchGraduateCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
	}
}

void AWitchGraduatePlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);
	if (HitResult.bBlockingHit)
	{
		// We hit something, move there
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AWitchGraduatePlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if ((Distance > 120.0f))
		{
			UAIBlueprintHelperLibrary::SimpleMoveToLocation(this, DestLocation);
		}
	}
}

void AWitchGraduatePlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AWitchGraduatePlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}

void AWitchGraduatePlayerController::OnThrowProjectile() {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Red, TEXT("ThrowProjectile"));
	if (AWitchGraduateCharacter* MyPawn = Cast<AWitchGraduateCharacter>(GetPawn())) {
		// Attempt to fire a projectile.
		if (MyPawn->ProjectileClass)
		{
			FRotator targetDirection;
			if (MyPawn->GetCursorToWorld())
			{
				targetDirection = (MyPawn->GetCursorToWorld()->GetComponentLocation() - MyPawn->GetActorLocation()).Rotation();
				targetDirection.Pitch = 0.0f;
			}

			// Set MuzzleOffset to spawn projectiles slightly in front of the camera.
			FVector SpawnOffset(50.0f, 0.0f, 50.0f);

			// Transform MuzzleOffset from camera space to world space.
			FVector ThrowingHandLocation = MyPawn->GetActorLocation() + FTransform(targetDirection).TransformVector(SpawnOffset);
			//targetDirection.Pitch = 45.0f;

			UWorld* World = GetWorld();
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = MyPawn;
				SpawnParams.Instigator = MyPawn->GetInstigator();

				// Spawn the projectile at the muzzle.
				AProjectile* Projectile = World->SpawnActor<AProjectile>(MyPawn->ProjectileClass, ThrowingHandLocation, targetDirection, SpawnParams);
				if (Projectile)
				{
					// Set the projectile's initial trajectory.
					FVector LaunchDirection = targetDirection.Vector();
					Projectile->ThrowInDirection(LaunchDirection);
				}
			}
		}
	}
}

void AWitchGraduatePlayerController::OnOpenChest() {
	if (actorUnderCursor) {
		AChest* chest = Cast<AChest>(actorUnderCursor);
		if (chest) {
			UInventoryComponent* inventory = chest->Open(nullptr);
			if (inventory) {
				UE_LOG(LogTemp, Warning, TEXT("Chest opened!"));
			}
		}
	}
}

void AWitchGraduatePlayerController::OnMainAction() {
	switch (cursorState) {
	case OnField:
		OnThrowProjectile();

	case OnChest:
		OnOpenChest();
	}
}