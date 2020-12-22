// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/AssetManager.h"

UENUM()
enum class ESkillType : uint8 {
	EST_MELEE UMETA(DisplayName = "近战类"),
	EST_RANGED UMETA(DisplayName = "远程类"),
	EST_ROLL UMETA(DisplayName = "翻滚类"),
	EST_Effect UMETA(DisplayName = "效果类")
};

/// 无用
class ADEMO_API ADemoEnum
{
public:
	ADemoEnum();
	~ADemoEnum();
};
