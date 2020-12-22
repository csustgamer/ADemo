// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "ADemoDamageExecution.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoDamageExecution : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UADemoDamageExecution();
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, OUT FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;
};
