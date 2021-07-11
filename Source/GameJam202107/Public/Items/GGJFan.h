// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"
#include "GGJFan.generated.h"

/**
 * ∑Á…»
 */
UCLASS()
class GAMEJAM202107_API AGGJFan : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJFan();

	virtual void Tick(float DeltaTime);

	virtual void BeginPlay();


public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		float GravitationPower = 2000;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UBoxComponent*BoxComp;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound")
		class USoundBase*sound;
};
