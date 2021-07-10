// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/GGJItemBase.h"
#include "GGJSpines.generated.h"

/**
 * 
 */
UCLASS()
class GAMEJAM202107_API AGGJSpines : public AGGJItemBase
{
	GENERATED_BODY()
public:
	AGGJSpines();

	UFUNCTION()
	void BoxCompOverlapping(
		UPrimitiveComponent* OverlappedComponent,
		AActor* OtherActor,
		UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, 
		const FHitResult & SweepResult);
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Gravity")
		class UBoxComponent*BoxComp;

};
