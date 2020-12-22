// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADemoGameplayAbilityBase.h"
#include "ADemoEnum.h"
#include "ADemoGameplayAbilitySpawn.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoGameplayAbilitySpawn : public UADemoGameplayAbilityBase
{
	GENERATED_BODY()
	
public:

	// 抛出指定的Actor，经过一定逻辑后判断该Actor是否会被触发
	UFUNCTION(BlueprintCallable)
	bool Spawn(TSubclassOf<AActor> type);
};
