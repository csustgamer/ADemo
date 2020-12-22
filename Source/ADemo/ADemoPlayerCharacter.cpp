// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoPlayerCharacter.h"

void AADemoPlayerCharacter::ObtainItem(UADemoItem* item)
{
	if (!item->CanRepeatedObtain) {
		if (ObtainedItem.Contains(item->GetPrimaryAssetId())) {
			return;
		}
		ObtainedItem.Add(item->GetPrimaryAssetId());
	}
	item->Apply2Character(this);
}

void AADemoPlayerCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	check(PlayerInputComponent);
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	// PlayerInputComponent->BindAxis("MoveForward", this, &AADemoPlayerCharacter::MoveForward);
	// PlayerInputComponent->BindAxis("MoveRight", this, &AADemoPlayerCharacter::MoveRight);
	//
	// PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	// PlayerInputComponent->BindAxis("TurnRate", this, &AADemoPlayerCharacter::TurnAtRate);
	// PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	// PlayerInputComponent->BindAxis("LookUpRate", this, &AADemoPlayerCharacter::LookUpAtRate);
}

void AADemoPlayerCharacter::MoveForward(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AADemoPlayerCharacter::MoveRight(float Value)
{
	if ((Controller != NULL) && (Value != 0.0f))
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AADemoPlayerCharacter::TurnAtRate(float Rate)
{
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AADemoPlayerCharacter::LookUpAtRate(float Rate)
{
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

