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
	
	int32 result = AddFunction(number1, number2);
	UE_LOG(LogTemp, Warning, TEXT("AddFunction Result: %d"), result);
	
	if (number1 > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10보다 큽니다."));
	}
}

// Called every frame
void ACodingTestActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

int ACodingTestActor::AddFunction(int num1, int num2)
{
	int result = num1 + num2;
	return result;
}

int ACodingTestActor::SubtractFunction(int num1, int num2)
{
	return num1 - num2;
}

int ACodingTestActor::MultiplyFunction(int num1, int num2)
{
	return num1 * num2;
}
