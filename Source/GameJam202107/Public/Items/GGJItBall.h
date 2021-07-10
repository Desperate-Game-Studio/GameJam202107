// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"
#include "GGJItBall.generated.h"

/**
 * ��Ҳ�����С��
 */
UCLASS()
class GAMEJAM202107_API AGGJItBall : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJItBall();

	// ������Ϸʤ���Լ������Ľ��
	UFUNCTION(BlueprintImplementableEvent)
	void HandleGame(bool result);


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UBoxComponent*BoxComp;
};
