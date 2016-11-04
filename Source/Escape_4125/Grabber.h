// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPE_4125_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;


private:
	//How far ahead of the player can we reach in cm
	UPROPERTY(VisibleAnywhere)
	float Reach = 100.0f;

	UPhysicsHandleComponent* PhysicsHandle = nullptr;
	
	UInputComponent* InputComponent = nullptr;

	//Ray-cast and grab what in reach
	void Grab();
	//Called when grab is released
	void Release();
	//Find attached physics handle
	void FindPhysicsHandleComponent();
	//Setup (asumed) attached input component
	void SetupInputComponent();
	//Return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
