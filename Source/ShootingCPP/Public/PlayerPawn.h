// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SHOOTINGCPP_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;
	
	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;
	
	UPROPERTY(EditAnywhere)
	class UInputMappingContext* imc_playerInput;
	
	UPROPERTY(EditAnywhere)
	class UInputAction* ia_horizontal;
	
	UPROPERTY(EditAnywhere)
	class UInputAction* ia_vertical;
	
	UPROPERTY(EditAnywhere)
	float moveSpeed = 500;
	
	UPROPERTY(EditAnywhere)
	class UArrowComponent* firePosition;
	
	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABullet> bulletFactory;
	
private:
	float h;
	float v;
	
	void MoveHorizontal(float value);
	void MoveVertical(float value);
	
	// Enhanced Input 액션 이벤트 콜백 함수
	void OnInputHorizontal(const struct FInputActionValue& value);
	void OnInputVertical(const struct FInputActionValue& value);

	void Fire();
	
};
