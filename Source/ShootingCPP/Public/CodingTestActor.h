// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CodingTestActor.generated.h"

UCLASS()
class SHOOTINGCPP_API ACodingTestActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACodingTestActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
    
	/*
	UPROPERTY(EditAnywhere)
    int32 number1 = 10;
	
	UPROPERTY(VisibleAnywhere)
	float number2 = 3.14f;
	
	//FString name = "Park Won Seok";
	FString name = TEXT("박원석");
	*/
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 number1 = 10;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 number2 = 30;
	
	//FString name = "Park Won Seok";
	UPROPERTY(EditInstanceOnly, BlueprintReadOnly)
	FString name = TEXT("박원석");
	
	bool isReady = true;
	bool isFinished = false;
	
	//더하기 함수 선언
	//UFUNCTION(BlueprintCallable)
	UFUNCTION(BlueprintPure)			
	int32 AddFunction(int32 num1, int32 num2);

	//빼기 및 곱하기, 나눗셈 함수 선언
	UFUNCTION(BlueprintPure)
	int32 SubtractFunction(int32 num1, int32 num2);

	UFUNCTION(BlueprintPure)
	int32 MultiplyFunction(int32 num1, int32 num2);

	UFUNCTION(BlueprintPure)
	float DivideFunction(float num1, float num2);
};
