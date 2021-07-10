// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJSpines.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include "Items/GGJItBall.h"

AGGJSpines::AGGJSpines()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh->SetSimulatePhysics(true);

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetupAttachment(RootComponent);

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGGJSpines::BoxCompOverlapping);


}

void AGGJSpines::BoxCompOverlapping(UPrimitiveComponent* OverlappedComponent, 
	AActor* OtherActor, UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AGGJItBall*ball = Cast<AGGJItBall>(OtherActor);

	if (ball)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Over!!!"));
		UE_LOG(LogTemp, Warning, TEXT("The ball destory by Spaines"));
		ball->HandleGame(false);
	}
}
