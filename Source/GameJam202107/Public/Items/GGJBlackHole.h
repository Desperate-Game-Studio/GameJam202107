// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"

#include "GGJBlackHole.generated.h"

/**
 * 黑洞
 */
UCLASS()
class GAMEJAM202107_API AGGJBlackHole : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJBlackHole();
	void BeginPlay();
	void Tick(float DeltaTime);

	// 引力斥力函数
	UFUNCTION(BlueprintCallable)
		void OpenGravitational(float IsRepulsion);

	UFUNCTION(BlueprintCallable)
		void InnerSphere(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	class UParticleSystem*Rail;

	// 球体范围内的物体会受到玩家的操作来开启引力或者斥力
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class USphereComponent*OutterSphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class USphereComponent*InnerSphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		float GravitationPower = 2000;


};
