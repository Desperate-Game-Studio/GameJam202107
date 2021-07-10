// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GGJItemBase.generated.h"



/*
 	这个类用于场景当中所有可以进行交互的物体
    1.风扇：将小球向某个方向吹
	2.黑洞：将小球向该物体的核心位置吸附，发生碰撞则游戏失败
	3.炮台：定期发射激光炮，弹道碰到小球则游戏失败
	4.激光网：玩家电磁板能通过但小球无法通过的障碍，小球触碰则游戏失败
	5.尖刺：经典尖刺，小球碰到则游戏失败，可以被放置在任何关卡建筑上"
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
