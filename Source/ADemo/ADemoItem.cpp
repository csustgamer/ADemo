// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoItem.h"

const FPrimaryAssetType	UADemoItem::PassiveSkillItemType = TEXT("PassiveSkill");
const FPrimaryAssetType	UADemoItem::NormalSkillItemType = TEXT("NormalSkill");

void UADemoItem::Apply2Character_Implementation(class AADemoPlayerCharacter* character) const
{

}

FPrimaryAssetId UADemoItem::GetPrimaryAssetId() const
{
	return FPrimaryAssetId(ItemType,GetFName());
}
