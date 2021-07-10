// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJBlackHole.h"
#include <Components/SphereComponent.h>
#include "Engine/World.h"
#include <Items/GGJItBall.h>

AGGJBlackHole::AGGJBlackHole()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;

	OutterSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("GravitationalSphere"));
	OutterSphereComp->SetSphereRadius(200.0f);
	OutterSphereComp->SetupAttachment(RootComponent);

	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	

	InnerSphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("InnerSphereComp"));
	InnerSphereComp->SetSphereRadius(50.0f);
	InnerSphereComp->SetupAttachment(RootComponent);
	InnerSphereComp->OnComponentBeginOverlap.AddDynamic(this,&AGGJBlackHole::InnerSphere);

}

void AGGJBlackHole::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	OpenGravitational(FMath::Sin(this->GetGameTimeSinceCreation()));

}

void AGGJBlackHole::OpenGravitational(float IsRepulsion)
{
	TArray<UPrimitiveComponent*>OverlappingComops;
	OutterSphereComp->GetOverlappingComponents(OverlappingComops);

	for (int32 i = 0; i < OverlappingComops.Num(); i++)
	{
		UPrimitiveComponent*PrimComp = OverlappingComops[i];
		if (PrimComp&&PrimComp->IsSimulatingPhysics())
		{
			const float GravitationRadius = OutterSphereComp->GetScaledSphereRadius();// 引力半径获取
			const float	Power = GravitationPower * IsRepulsion;// 引力大小

			PrimComp->AddRadialForce(GetActorLocation(), GravitationRadius, Power, ERadialImpulseFalloff::RIF_Constant, true);
		}
	}
}
void AGGJBlackHole::InnerSphere(
	UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult & SweepResult)
{
	AGGJItBall*ball = Cast<AGGJItBall>(OtherActor);

	if (ball)
	{
		ball->HandleGame(false);
	}
}
