// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"

#include "GGJBlackHole.generated.h"

/**
 * �ڶ�
 */
UCLASS()
class GAMEJAM202107_API AGGJBlackHole : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJBlackHole();
	void BeginPlay();
	void Tick(float DeltaTime);

	// ������������
	UFUNCTION(BlueprintCallable)
		void OpenGravitational(float IsRepulsion);

	UFUNCTION(BlueprintCallable)
		void InnerSphere(UPrimitiveComponent* OverlappedComponent,
			AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	class UParticleSystem*Rail;

	// ���巶Χ�ڵ�������ܵ���ҵĲ����������������߳���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class USphereComponent*OutterSphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class USphereComponent*InnerSphereComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		float GravitationPower = 2000;


};
