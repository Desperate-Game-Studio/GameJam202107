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

	// 开启引力或者开启斥力
	void OpenGravitation(float value);

	// 一个球体作为角色碰撞的范围。
	// 球体范围内的物体会受到玩家的操作来开启引力或者斥力
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Gravity")
	class USphereComponent*GravitationalSphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
	float GravitationPower = 2000;

	// 引力斥力函数
	UFUNCTION(BlueprintCallable)
	void OpenGravitational(float IsRepulsion);

};
