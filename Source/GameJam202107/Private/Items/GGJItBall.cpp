// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJItBall.h"
#include <Components/BoxComponent.h>

AGGJItBall::AGGJItBall()
{
	PrimaryActorTick.bCanEverTick = true;


	Mesh->SetSimulatePhysics(true);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetupAttachment(RootComponent);

}


