// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FloatingPlatform.generated.h"

UCLASS()
class SHOOTTHEMUP_API AFloatingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFloatingPlatform();

	UPROPERTY(VisibleAnywhere,BlueprintReadOnly,Category="Platform")
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Platform")
	FVector StartPoint = FVector(0.f);;

	UPROPERTY(EditAnywhere,meta=(MakeEditWidget ="true"))
	FVector EndPoint= FVector(0.f);

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Platform")
	float InterpSpeed = 4;
	
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Platform")
	float InterpTime = 4;
	

	FTimerHandle InterpTimer;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category="Platform")
	bool bInterp = false;

	float Distance;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void ToggleInterp();

	void SwapVectors(FVector& VecOne,FVector& VecTwo);
};
