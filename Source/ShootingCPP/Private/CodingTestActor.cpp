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
	//UE_LOG(LogTemp, Warning, TEXT("Hello World"));
	//UE_LOG(LogTemp, Warning, TEXT("%d"), number1);
	//UE_LOG(LogTemp, Warning, TEXT("%.2f"), number2);
	//UE_LOG(LogTemp, Warning, TEXT("Name: %s"), *name);
	//UE_LOG(LogTemp, Warning, TEXT("isReady: %d, isFinished: %d"), isReady, isFinished);
	
	int result = AddFunction(number1, number2);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), result);
	//UE_LOG(LogTemp, Warning, TEXT("%d"), static_cast<int>(result));
	
	if (number1 > 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("numer1의 값이 10보다 큽니다."));
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

