// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"
#include "GGJRailgun.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM202107_API AGGJRailgun : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJRailgun();

	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

	UFUNCTION()
		void BoxCompOverlapping(
			UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep,
			const FHitResult & SweepResult);

	UFUNCTION()
		void SetCollision();// 使用定时器来设置box的碰撞，以此来开启激光炮
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UBoxComponent*BoxComp;

	FTimerHandle  Hand;
};
