// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoNormalSkillItem.h"
#include "ADemoPlayerCharacter.h"

UADemoNormalSkillItem::UADemoNormalSkillItem()
{
	ItemType = UADemoItem::NormalSkillItemType;
}

void UADemoNormalSkillItem::Apply2Character_Implementation(class AADemoPlayerCharacter* character) const
{
	if (!character->OwnSpawnActorSet.Contains(SkillSpawnActor)) {
		character->OwnSpawnActorSet.Add(SkillSpawnActor);
	}
}
