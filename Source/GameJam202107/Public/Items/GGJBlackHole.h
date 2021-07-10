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
	void Tick(float DeltaTime);

	// ������������
	UFUNCTION(BlueprintCallable)
		void OpenGravitational(float IsRepulsion);

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UStaticMeshComponent*Mesh;

	// ���巶Χ�ڵ�������ܵ���ҵĲ����������������߳���
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class USphereComponent*GravitationalSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		float GravitationPower = 2000;


};
