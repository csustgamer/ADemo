// Fill out your copyright notice in the Description page of Project Settings.


#include "ADemoCharacterBase.h"
#include "ADemoAbilitySystemComponent.h"

// Sets default values
AADemoCharacterBase::AADemoCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AbilitySystemComp = CreateDefaultSubobject<UADemoAbilitySystemComponent>(TEXT("AbilitySystemComp"));
	// AbilitySystemComp->SetIsReplicated(true);

	// Create the attribute set, this replicates by default
	AttributeSet = CreateDefaultSubobject<UADemoAttributeSet>(TEXT("AttributeSet"));
}

// Called when the game starts or when spawned
void AADemoCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	for (auto& Ability : AbilityMap) {
		GiveAbility(Ability.Value);
	}
}

// Called every frame
void AADemoCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AADemoCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

UAbilitySystemComponent* AADemoCharacterBase::GetAbilitySystemComponent() const
{
	return AbilitySystemComp;
}

void AADemoCharacterBase::ApplyPassiveEffect(TSubclassOf<UGameplayEffect> effect)
{
	FGameplayEffectContextHandle EffectContext = AbilitySystemComp->MakeEffectContext();
	EffectContext.AddSourceObject(this);

	FGameplayEffectSpecHandle NewHandle = AbilitySystemComp->MakeOutgoingSpec(effect, 1, EffectContext);
	if (NewHandle.IsValid())
	{
		FActiveGameplayEffectHandle ActiveGEHandle = AbilitySystemComp->ApplyGameplayEffectSpecToTarget(*NewHandle.Data.Get(), AbilitySystemComp);
	}
}

bool AADemoCharacterBase::ActiveAbility(ESkillType type)
{
	if(!AbilityMap.Contains(type)) return false;
	return AbilitySystemComp->TryActivateAbilityByClass(AbilityMap[type],false);
}

void AADemoCharacterBase::GiveAbility(TSubclassOf<UADemoGameplayAbilityBase> ability)
{
	auto handle = AbilitySystemComp->GiveAbility(FGameplayAbilitySpec(ability,1, INDEX_NONE,this));
	
}

void AADemoCharacterBase::GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<class UADemoGameplayAbilityBase*>& ActiveAbilities)
{
	if (AbilitySystemComp)
	{
		AbilitySystemComp->GetActiveAbilitiesWithTags(AbilityTags, ActiveAbilities);
	}
}

float AADemoCharacterBase::GetHealth() const
{
	return AttributeSet->GetHealth();
}

float AADemoCharacterBase::GetMaxHealth() const
{
	return AttributeSet->GetMaxHealth();
}

float AADemoCharacterBase::GetMana() const
{
	return AttributeSet->GetMana();
}

float AADemoCharacterBase::GetMaxMana() const
{
	return AttributeSet->GetMana();
}

