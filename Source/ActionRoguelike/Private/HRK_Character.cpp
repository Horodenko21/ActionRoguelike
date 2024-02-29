// Fill out your copyright notice in the Description page of Project Settings.


#include "HRK_Character.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
AHRK_Character::AHRK_Character()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	// Instanciando objetos criados
	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");

	// "Linka" SpringArmComponent ao primeiro objeto na classe de HRK_Character
	SpringArmComponent->SetupAttachment(RootComponent);

	// Instanciando objetos criados
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");

	// "Linka" CameraComp ao SpringArmComponent
	CameraComp->SetupAttachment(SpringArmComponent);

}

// Called when the game starts or when spawned
void AHRK_Character::BeginPlay()
{
	Super::BeginPlay();
	
}

void AHRK_Character::MoveForward(float Value)
{
	AddMovementInput(GetActorForwardVector(), Value);
}

// Called every frame
void AHRK_Character::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AHRK_Character::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AHRK_Character::MoveForward);
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}

