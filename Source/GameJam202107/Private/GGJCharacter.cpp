// Fill out your copyright notice in the Description page of Project Settings.


#include "GGJCharacter.h"
#include <Components/SphereComponent.h>
#include "Engine/World.h"

// Sets default values
AGGJCharacter::AGGJCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	GravitationalSphere = CreateDefaultSubobject<USphereComponent>(TEXT("GravitationalSphere"));
	GravitationalSphere->SetSphereRadius(2000.0f);
	GravitationalSphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void AGGJCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGGJCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGGJCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("OpenGravitation", this, &AGGJCharacter::OpenGravitation);
	
}

void AGGJCharacter::OpenGravitation(float value)
{

	OpenGravitational(value);
	if (value)
	{
		GEngine->AddOnScreenDebugMessage(-1, 0.75f, FColor::Black, TEXT("Open Gravitation"));
	}
	
}


void AGGJCharacter::OpenGravitational(float IsRepulsion)
{
	TArray<UPrimitiveComponent*>OverlappingComops;
	GravitationalSphere->GetOverlappingComponents(OverlappingComops);

	for (int32 i=0;i<OverlappingComops.Num();i++)
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

