// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/GGJWinTriger.h"
#include <Components/BoxComponent.h>
#include <Items/GGJItBall.h>


AGGJWinTriger::AGGJWinTriger()
{
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	BoxComp->SetBoxExtent(FVector(100.0f, 100.0f, 100.0f));
	BoxComp->SetupAttachment(RootComponent);
	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &AGGJWinTriger::BoxCompOverlapping);
}

void AGGJWinTriger::BoxCompOverlapping(UPrimitiveComponent * OverlappedComponent, AActor * OtherActor,
	UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	AGGJItBall*ball = Cast<AGGJItBall>(OtherActor);

	if (ball)
	{
		UE_LOG(LogTemp, Warning, TEXT("Congratulations on the victory!!!"));

		ball->HandleGame(true);
	}
}

