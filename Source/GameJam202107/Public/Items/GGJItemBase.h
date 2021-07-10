// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGJItemBase.generated.h"



/*
 	��������ڳ����������п��Խ��н���������
    1.���ȣ���С����ĳ������
	2.�ڶ�����С���������ĺ���λ��������������ײ����Ϸʧ��
	3.��̨�����ڷ��伤���ڣ���������С������Ϸʧ��
	4.����������ҵ�Ű���ͨ����С���޷�ͨ�����ϰ���С��������Ϸʧ��
	5.��̣������̣�С����������Ϸʧ�ܣ����Ա��������κιؿ�������"
*/


UCLASS()
class GAMEJAM202107_API AGGJItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGGJItemBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
};
