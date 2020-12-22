// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADemoItem.h"
#include "ADemoPassiveSkillItem.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoPassiveSikllItem : public UADemoItem
{
	GENERATED_BODY()
public:
	UADemoPassiveSikllItem();
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Skill)
	TSubclassOf<class UGameplayEffect> PassiveEffect;

	void Apply2Character_Implementation(class AADemoPlayerCharacter* character)const override;
};
