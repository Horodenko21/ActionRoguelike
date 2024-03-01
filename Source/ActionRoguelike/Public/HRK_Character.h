// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "HRK_Character.generated.h"

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class ACTIONROGUELIKE_API AHRK_Character : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AHRK_Character();

protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;

protected:

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* CameraComp;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
