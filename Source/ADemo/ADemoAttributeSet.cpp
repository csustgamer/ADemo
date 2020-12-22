// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoAttributeSet.h"

#include "ADemoCharacterBase.h"
#include "GameplayEffect.h"
#include "GameplayEffectExtension.h"

UADemoAttributeSet::UADemoAttributeSet():
	MaxHealth(5.f),
	Health(5.f),
	Mana(100.f),
	MaxMana(100.f),
	AttackPower(1.f),
	DefensePower(0.f),
	Damage(0.f)
{

}

// 用来对数据的最后的范围限制和修改后的事件分发
void UADemoAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	float DeltaValue = 0.f;
	if(Data.EvaluatedData.ModifierOp == EGameplayModOp::Additive)
	{
		DeltaValue = Data.EvaluatedData.Magnitude;
	}

	// Get the Target actor, which should be our owner
	AActor* TargetActor = nullptr;
	AController* TargetController = nullptr;
	AADemoCharacterBase* TargetCharacter = nullptr;
	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		TargetActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		TargetCharacter = Cast<AADemoCharacterBase>(TargetActor);
	}

	if (Data.EvaluatedData.Attribute == GetDamageAttribute())
	{
		const float LocalDamageDone = GetDamage();
		SetDamage(0.f);
		if (LocalDamageDone > 0)
		{
			// Apply the health change and then clamp it
			const float OldHealth = GetHealth();
			SetHealth(FMath::Clamp(OldHealth - LocalDamageDone, 0.0f, GetMaxHealth()));

			if (TargetCharacter)
			{
				// This is proper damage
				TargetCharacter->HandleDamage(LocalDamageDone);

				// Call for all health changes
				TargetCharacter->HandleHPChanged(GetHealth(),GetMaxHealth());
			}
		}
	}else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(), 0.0f, GetMaxHealth()));

		if (TargetCharacter)
		{
			// Call for all health changes
			TargetCharacter->HandleHPChanged(GetHealth(),GetMaxHealth());
		}
	}else if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		// Clamp mana
		SetMana(FMath::Clamp(GetMana(), 0.0f, GetMaxMana()));

		if (TargetCharacter)
		{
			// Call for all mana changes
			TargetCharacter->HandleManaChanged(GetMana(),GetMaxMana());
		}
	}
	
}
