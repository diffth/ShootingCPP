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
	
	// int32 addResult = AddFunction(number1, number2);

	if (number1 >= 100)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 100보다 큽니다."));
	}
	else if (number1 >= 10)
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10 이상 100 미만입니다."));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("number1의 값이 10 이하입니다."));
	}
	if (isReady)
	{
		// Add 함수를 실행한다.
		int32 result = AddFunction(number1, number2);
		UE_LOG(LogTemp, Warning, TEXT("%d"), result);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("아직 준비가 안됐습니다."));
	}
	for (int32 i=0; i<100; i++)
	{
		int32 result = i % 2;
		
		if (result == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("%d는 짝수입니다."), i);
		}
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
