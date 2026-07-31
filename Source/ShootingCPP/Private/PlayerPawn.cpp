#include "PlayerPawn.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Components/ArrowComponent.h"
#include "Bullet.h"
#include "UObject/ConstructorHelpers.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerPawn::APlayerPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("My Box Component"));
	
	SetRootComponent(boxComp);
	
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Static Mesh"));
	
	meshComp->SetupAttachment(boxComp);
	
	FVector boxSize = FVector(50.0f, 50.0f, 50.0f);
	boxComp->SetBoxExtent(boxSize);
	
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("Fire Position"));
	firePosition->SetupAttachment(boxComp);
	// 총알 발사 위치를 플레이어 상단(+Z)으로 옮기고 위쪽(Pitch=90)을 향하게 설정
	firePosition->SetRelativeLocation(FVector(0.0f, 0.0f, 100.0f));
	firePosition->SetRelativeRotation(FRotator(90.0f, 0.0f, 0.0f));

	// BP_Bullet 블루프린트 클래스를 기본 발사체 공장(bulletFactory)으로 지정
	static ConstructorHelpers::FClassFinder<ABullet> defaultBulletClass(TEXT("/Game/Blueprints/BP_Bullet.BP_Bullet_C"));
	if (defaultBulletClass.Succeeded())
	{
		bulletFactory = defaultBulletClass.Class;
	}
}

// Called when the game starts or when spawned
void APlayerPawn::BeginPlay()
{
	Super::BeginPlay();
	
	APlayerController* pc = GetWorld()->GetFirstPlayerController();
	
	if (pc != nullptr)
	{
		UEnhancedInputLocalPlayerSubsystem* subsys = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		
		if (subsys != nullptr)
		{
			subsys->AddMappingContext(imc_playerInput,0);
		}
	}
}

// Called every frame
void APlayerPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector dir = FVector(0, h, v);
	dir.Normalize();
	
	FVector newLocation = GetActorLocation() + dir * moveSpeed * DeltaTime;
	
	SetActorLocation(newLocation);
}

// Called to bind functionality to input
void APlayerPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	UEnhancedInputComponent* enhancedInputComponent = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	if (enhancedInputComponent != nullptr)
	{
		enhancedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Triggered, this, &APlayerPawn::OnInputHorizontal);
		enhancedInputComponent->BindAction(ia_horizontal, ETriggerEvent::Completed, this, &APlayerPawn::OnInputHorizontal);
		enhancedInputComponent->BindAction(ia_vertical, ETriggerEvent::Triggered, this, &APlayerPawn::OnInputVertical);
		enhancedInputComponent->BindAction(ia_vertical, ETriggerEvent::Completed, this, &APlayerPawn::OnInputVertical);
		
		enhancedInputComponent->BindAction(ia_fire, ETriggerEvent::Started, this, &APlayerPawn::Fire);
	}
}

// 좌우 이동 입력 콜백
void APlayerPawn::OnInputHorizontal(const FInputActionValue& value)
{
	// TODO: 좌우 이동 처리 로직 작성
	// float hor = value.Get<float>();
	// UE_LOG(LogTemp, Warning, TEXT("Horizontal: %.2f"), hor);
	h = value.Get<float>();
}

// 상하 이동 입력 콜백
void APlayerPawn::OnInputVertical(const FInputActionValue& value)
{
	// TODO: 상하 이동 처리 로직 작성
	// float ver = value.Get<float>();
	// UE_LOG(LogTemp, Warning, TEXT("Vertical: %.2f"), ver);
	v = value.Get<float>();
}

void APlayerPawn::Fire()
{
	if (bulletFactory != nullptr)
	{
		FActorSpawnParameters params;
		params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

		GetWorld()->SpawnActor<ABullet>(bulletFactory, firePosition->GetComponentLocation(), firePosition->GetComponentRotation(), params);
		
		UGameplayStatics::PlaySound2D(GetWorld(), fireSound);
	}
}

void APlayerPawn::MoveHorizontal(float value)
{
	h = value;
}

void APlayerPawn::MoveVertical(float value)
{
	v = value;
}









