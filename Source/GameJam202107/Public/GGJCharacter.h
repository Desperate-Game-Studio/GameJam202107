// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GGJCharacter.generated.h"

UCLASS()
class GAMEJAM202107_API AGGJCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGGJCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	// �����������߿�������
	void OpenGravitation(float value);

	// һ��������Ϊ��ɫ��ײ�ķ�Χ��
	// ���巶Χ�ڵ�������ܵ���ҵĲ����������������߳���
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gravity")
	class USphereComponent*GravitationalSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	float GravitationPower = 2000;

	// ������������
	UFUNCTION(BlueprintCallable)
	void OpenGravitational(float IsRepulsion);

};
