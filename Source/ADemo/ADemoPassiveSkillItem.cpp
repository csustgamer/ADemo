// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoPassiveSkillItem.h"
#include "ADemoPlayerCharacter.h"

UADemoPassiveSikllItem::UADemoPassiveSikllItem()
{
	ItemType = UADemoItem::PassiveSkillItemType;
}

void UADemoPassiveSikllItem::Apply2Character_Implementation(class AADemoPlayerCharacter* character) const
{
	character->ApplyPassiveEffect(PassiveEffect);
}
