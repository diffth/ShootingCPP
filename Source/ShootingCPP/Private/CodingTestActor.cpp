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
	int32 subResult = SubtractFunction(number1, number2);
	int32 mulResult = MultiplyFunction(number1, number2);
	float divResult = DivideFunction(static_cast<float>(number1), static_cast<float>(number2));

	UE_LOG(LogTemp, Warning, TEXT("AddFunction Result: %d"), addResult);
	UE_LOG(LogTemp, Warning, TEXT("SubtractFunction Result: %d"), subResult);
	UE_LOG(LogTemp, Warning, TEXT("MultiplyFunction Result: %d"), mulResult);
	UE_LOG(LogTemp, Warning, TEXT("DivideFunction Result: %.2f"), divResult);
	
	if (number1 > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10보다 큽니다."));
	}

	TArray<int32> testArray = { 10, 20, 30, 40, 50 };
	PrintArrayElements(testArray);
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

int32 ACodingTestActor::SubtractFunction(int32 num1, int32 num2)
{
	return num1 - num2;
}

int32 ACodingTestActor::MultiplyFunction(int32 num1, int32 num2)
{
	return num1 * num2;
}

float ACodingTestActor::DivideFunction(float num1, float num2)
{
	if (num2 == 0.0f)
	{
		UE_LOG(LogTemp, Error, TEXT("Divide by zero!"));
		return 0.0f;
	}
	return num1 / num2;
}

void ACodingTestActor::PrintArrayElements(const TArray<int32>& numbers)
{
	for (int32 i = 0; i < numbers.Num(); ++i)
	{
		UE_LOG(LogTemp, Log, TEXT("Array[%d]: %d"), i, numbers[i]);
	}
}
