// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AbilitySystemComponent.h"
#include "ADemoAbilitySystemComponent.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoAbilitySystemComponent : public UAbilitySystemComponent
{
	GENERATED_BODY()
public:
	/** Returns a list of currently active ability instances that match the tags */
	void GetActiveAbilitiesWithTags(const FGameplayTagContainer& GameplayTagContainer, TArray<class UADemoGameplayAbilityBase*>& ActiveAbilities);
};
