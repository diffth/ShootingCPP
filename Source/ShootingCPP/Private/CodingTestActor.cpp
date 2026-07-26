// Fill out your copyright notice in the Description page of Project Settings.

#include "CodingTestActor.h"

// Sets default values
ACodingTestActor::ACodingTestActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACodingTestActor::BeginPlay()
{
	Super::BeginPlay();
	
	int32 addResult = AddFunction(number1, number2);

	if (number1 > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10보다 큽니다."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10 이하입니다."));
	}

}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int32 ACodingTestActor::AddFunction(int32 num1, int32 num2)
{
	int32 result = num1 + num2;
	return result;
}
