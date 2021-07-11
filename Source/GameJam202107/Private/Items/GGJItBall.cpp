// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJItBall.h"
#include <Components/BoxComponent.h>
#include "Kismet/GameplayStatics.h"

AGGJItBall::AGGJItBall()
{
	PrimaryActorTick.bCanEverTick = true;


	Mesh->SetSimulatePhysics(true);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetupAttachment(RootComponent);

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGGJItBall::BoxCompOverlapping);
}


void AGGJItBall::BoxCompOverlapping(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor)
	{

		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), sound,GetActorLocation());
	}
}