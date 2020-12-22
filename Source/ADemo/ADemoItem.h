// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Styling/SlateBrush.h"
#include "ADemoEnum.h"
#include "ADemoItem.generated.h"

/**
 * 
 */
UCLASS()
class ADEMO_API UADemoItem : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	static const FPrimaryAssetType	PassiveSkillItemType;
	static const FPrimaryAssetType	NormalSkillItemType;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Item)
	FPrimaryAssetType ItemType;

	/** User-visible short name */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FText ItemName;

	/** User-visible long description */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FText ItemDescription;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	bool CanRepeatedObtain;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Item)
	FSlateBrush ItemIcon;

	UFUNCTION(BlueprintNativeEvent)
	void Apply2Character(class AADemoPlayerCharacter* character) const;

	virtual void Apply2Character_Implementation(class AADemoPlayerCharacter* character)const;

	/** Overridden to use saved type */
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
};
