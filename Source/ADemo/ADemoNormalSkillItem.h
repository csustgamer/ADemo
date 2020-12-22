// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ADemoItem.h"
#include "ADemoNormalSkillItem.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoNormalSkillItem : public UADemoItem
{
	GENERATED_BODY()
public:
	UADemoNormalSkillItem();
	
	void Apply2Character_Implementation(class AADemoPlayerCharacter* character)const override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Skill)
	TSubclassOf<AActor> SkillSpawnActor;
};
