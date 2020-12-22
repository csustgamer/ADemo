// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADemoCharacterBase.h"
#include "ADemoItem.h"
#include "ADemoPlayerCharacter.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API AADemoPlayerCharacter : public AADemoCharacterBase
{
	GENERATED_BODY()

private:
	TSet<FPrimaryAssetId> ObtainedItem;

public:

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseTurnRate=45.f;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
	float BaseLookUpRate=45.f;

	UFUNCTION(BlueprintCallable)
	void ObtainItem(UADemoItem* item);

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	/** Called for forwards/backward input */
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	/** Called for side to side input */
	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	/**
	 * Called via input to turn at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void TurnAtRate(float Rate);

	/**
	 * Called via input to turn look up/down at a given rate.
	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
	 */
	void LookUpAtRate(float Rate);
};
