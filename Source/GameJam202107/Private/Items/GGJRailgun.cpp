// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJRailgun.h"
#include <Components/BoxComponent.h>
#include <Items/GGJItBall.h>

AGGJRailgun::AGGJRailgun()
{
	PrimaryActorTick.bCanEverTick = true;

	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(1000.0f, 100.0f, 100.0f));
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGGJRailgun::BoxCompOverlapping);
}

void AGGJRailgun::BeginPlay()
{
	GetWorldTimerManager().SetTimer(Hand, this, &AGGJRailgun::SetCollision, 3.0f, true, -1.0f);
}

void AGGJRailgun::Tick(float DeltaTime)
{

}

void AGGJRailgun::BoxCompOverlapping(UPrimitiveComponent* OverlappedComponent,
	AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex,
	bool bFromSweep, const FHitResult & SweepResult)
{
	AGGJItBall*ball = Cast<AGGJItBall>(OtherActor);

	if (ball)
	{
		UE_LOG(LogTemp, Warning, TEXT("Game Over!!!"));
		UE_LOG(LogTemp, Warning, TEXT("The ball destory by Railgun"));
		ball->HandleGame(false);
	}
}

void AGGJRailgun::SetCollision()
{

	if (BoxComp->GetCollisionEnabled()== ECollisionEnabled::NoCollision)
	{
		BoxComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
		UE_LOG(LogTemp, Warning, TEXT("The Railgun BoxComp Query And Physics"));
	}
	else
	{
		BoxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		UE_LOG(LogTemp, Warning, TEXT("The Railgun BoxComp No Collision"));
	}

}
