// Fill out your copyright notice in the Description page of Project Settings.


#include "FloatingPlatform.h"

// Sets default values
AFloatingPlatform::AFloatingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");
	RootComponent = Mesh;
	
	
}

// Called when the game starts or when spawned
void AFloatingPlatform::BeginPlay()
{
	Super::BeginPlay();

	StartPoint=GetActorLocation();
	EndPoint += StartPoint;
	
	GetWorldTimerManager().SetTimer(InterpTimer,this,&AFloatingPlatform::ToggleInterp,InterpTime);

	Distance = (EndPoint - StartPoint).Size();
}

// Called every frame
void AFloatingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(bInterp)
	{
		FVector CurrentLocation = GetActorLocation();
		FVector Interp = FMath::VInterpTo(CurrentLocation,EndPoint,DeltaTime,InterpSpeed);
		SetActorLocation(Interp);

		float DistanceTraveled = (GetActorLocation() - StartPoint).Size();

		if(Distance - DistanceTraveled <= 1.f)
		{
			ToggleInterp();

			GetWorldTimerManager().SetTimer(InterpTimer,this,&AFloatingPlatform::ToggleInterp,InterpTime);
			SwapVectors(StartPoint,EndPoint);
		}
	}
}

void AFloatingPlatform::ToggleInterp()
{
	bInterp = !bInterp;
}

void AFloatingPlatform::SwapVectors(FVector& VecOne, FVector& VecTwo)
{
	FVector Temp = VecOne;
	VecOne = VecTwo;
	VecTwo = Temp;
}

