// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoDamageExecution.h"
#include "ADemoAttributeSet.h"

struct ADemoDamageStatics
{
	DECLARE_ATTRIBUTE_CAPTUREDEF(DefensePower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(AttackPower);
	DECLARE_ATTRIBUTE_CAPTUREDEF(Damage);

	ADemoDamageStatics()
	{
		DEFINE_ATTRIBUTE_CAPTUREDEF(UADemoAttributeSet, DefensePower, Target, false);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UADemoAttributeSet, AttackPower, Source, true);

		DEFINE_ATTRIBUTE_CAPTUREDEF(UADemoAttributeSet, Damage, Source, true);
	}
};

static const ADemoDamageStatics& DamageStatics()
{
	static ADemoDamageStatics DmgStatics;
	return DmgStatics;
}

UADemoDamageExecution::UADemoDamageExecution()
{
	RelevantAttributesToCapture.Add(DamageStatics().DefensePowerDef);
	RelevantAttributesToCapture.Add(DamageStatics().AttackPowerDef);
	RelevantAttributesToCapture.Add(DamageStatics().DamageDef);
}

void UADemoDamageExecution::Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams,
	FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = ExecutionParams.GetTargetAbilitySystemComponent();
	UAbilitySystemComponent* SourceAbilitySystemComponent = ExecutionParams.GetSourceAbilitySystemComponent();

	AActor* SourceActor = SourceAbilitySystemComponent ? SourceAbilitySystemComponent->AvatarActor : nullptr;
	AActor* TargetActor = TargetAbilitySystemComponent ? TargetAbilitySystemComponent->AvatarActor : nullptr;

	const FGameplayEffectSpec& spec = ExecutionParams.GetOwningSpec();

	const FGameplayTagContainer* sourceTags = spec.CapturedSourceTags.GetAggregatedTags();
	const FGameplayTagContainer* targetTags = spec.CapturedTargetTags.GetAggregatedTags();

	FAggregatorEvaluateParameters EvaluationParameters;
	EvaluationParameters.SourceTags = sourceTags;
	EvaluationParameters.TargetTags = targetTags;

	float DefensePower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DefensePowerDef,EvaluationParameters,DefensePower);

	float AttackPower = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().AttackPowerDef, EvaluationParameters, AttackPower);

	float Damage = 0.f;
	ExecutionParams.AttemptCalculateCapturedAttributeMagnitude(DamageStatics().DamageDef, EvaluationParameters, Damage);

	float DamageDone = Damage * AttackPower - DefensePower;
	if(Damage > 0.f)
	{
		OutExecutionOutput.AddOutputModifier(FGameplayModifierEvaluatedData(DamageStatics().DamageProperty,EGameplayModOp::Additive,DamageDone));
	}
}
