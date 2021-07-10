// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJFan.h"

AGGJFan::AGGJFan()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;


}

void AGGJFan::Tick(float DeltaTime)
{

}
