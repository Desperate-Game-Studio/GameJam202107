// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJBlackHole.h"
#include <Components/SphereComponent.h>
#include "Engine/World.h"

AGGJBlackHole::AGGJBlackHole()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	GravitationalSphere = CreateDefaultSubobject<USphereComponent>(TEXT("GravitationalSphere"));
	GravitationalSphere->SetSphereRadius(200.0f);
	GravitationalSphere->SetupAttachment(RootComponent);

}

void AGGJBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	OpenGravitational(FMath::Sin(this->GetGameTimeSinceCreation()));

}

void AGGJBlackHole::OpenGravitational(float IsRepulsion)
{
	TArray<UPrimitiveComponent*>OverlappingComops;
	GravitationalSphere->GetOverlappingComponents(OverlappingComops);

	for (int32 i = 0; i < OverlappingComops.Num(); i++)
	{
		UPrimitiveComponent*PrimComp = OverlappingComops[i];
		if (PrimComp&&PrimComp->IsSimulatingPhysics())
		{
			const float GravitationRadius = GravitationalSphere->GetScaledSphereRadius();// 引力半径获取
			const float	Power = GravitationPower * IsRepulsion;// 引力大小

			PrimComp->AddRadialForce(GetActorLocation(), GravitationRadius, Power, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
}
