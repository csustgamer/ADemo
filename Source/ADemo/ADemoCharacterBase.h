// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ADemoAttributeSet.h"
#include "AbilitySystemInterface.h"
#include "ADemoEnum.h"
#include "ADemoGameplayAbilityBase.h"
#include "ADemoCharacterBase.generated.h"


UCLASS()
class ADEMO_API AADemoCharacterBase : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AADemoCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	UPROPERTY()
	UADemoAttributeSet* AttributeSet;

	UPROPERTY(BlueprintReadOnly)
	class UADemoAbilitySystemComponent* AbilitySystemComp;

	UPROPERTY(EditDefaultsOnly)
	TMap<ESkillType,TSubclassOf<UADemoGameplayAbilityBase>> AbilityMap;

	UPROPERTY()
	TSet<TSubclassOf<AActor>> OwnSpawnActorSet;

	#pragma region Event
public:
	UFUNCTION(BlueprintImplementableEvent)
	void HandleHPChanged(float CurrHP,float MaxHP);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleManaChanged(float CurrMana,float MaxMana);

	UFUNCTION(BlueprintImplementableEvent)
	void HandleDamage(float damage);

	#pragma endregion

	#pragma region Ability System and Effect
	/// 应用被动效果
	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void ApplyPassiveEffect(TSubclassOf<UGameplayEffect> effect);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	bool ActiveAbility(ESkillType type);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GiveAbility(TSubclassOf<UADemoGameplayAbilityBase> ability);

	UFUNCTION(BlueprintCallable, Category = "Abilities")
	void GetActiveAbilitiesWithTags(FGameplayTagContainer AbilityTags, TArray<class UADemoGameplayAbilityBase*>& ActiveAbilities);
	#pragma endregion

	#pragma region AttributeSet Getter

	/** Returns current health, will be 0 if dead */
	UFUNCTION(BlueprintCallable)
	virtual float GetHealth() const;

	/** Returns maximum health, health will never be greater than this */
	UFUNCTION(BlueprintCallable)
	virtual float GetMaxHealth() const;

	/** Returns current mana */
	UFUNCTION(BlueprintCallable)
	virtual float GetMana() const;

	/** Returns maximum mana, mana will never be greater than this */
	UFUNCTION(BlueprintCallable)
	virtual float GetMaxMana() const;

	#pragma endregion

};
