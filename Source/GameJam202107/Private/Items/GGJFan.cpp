// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJFan.h"
#include <Components/BoxComponent.h>

AGGJFan::AGGJFan()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(1000.0f,100.0f,100.0f));
	
	
	BoxComp->SetupAttachment(RootComponent);
}

void AGGJFan::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TArray<UPrimitiveComponent*>OverlappingComops;
	BoxComp->GetOverlappingComponents(OverlappingComops);

	for (int32 i = 0; i < OverlappingComops.Num(); i++)
	{
		UPrimitiveComponent*PrimComp = OverlappingComops[i];
		if (PrimComp&&PrimComp->IsSimulatingPhysics())
		{
			PrimComp->AddImpulse(GetActorForwardVector() * GravitationPower, NAME_None, true);
		}
	}

}

