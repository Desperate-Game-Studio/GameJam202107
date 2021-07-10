// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"
#include "GGJItBall.generated.h"

/**
 * 玩家操作的小球
 */
UCLASS()
class GAMEJAM202107_API AGGJItBall : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJItBall();

	// 处理游戏胜利以及结束的结果
	UFUNCTION(BlueprintImplementableEvent)
	void HandleGame(bool result);


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UBoxComponent*BoxComp;
};
