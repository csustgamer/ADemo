// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoGameplayAbilitySpawn.h"
#include "ADemoCharacterBase.h"

bool UADemoGameplayAbilitySpawn::Spawn(TSubclassOf<AActor> type)
{
	AActor* actor = GetAvatarActorFromActorInfo();
	AADemoCharacterBase* character = Cast<AADemoCharacterBase>(actor);
	if (!character) return false;
	FVector pos = actor->GetActorLocation();
	FRotator rotation = actor->GetActorRotation();
	if (character->OwnSpawnActorSet.Contains(type)) {
		GetWorld()->SpawnActor<AActor>(type, pos, rotation);
		return true;
	}
	return false;
}
