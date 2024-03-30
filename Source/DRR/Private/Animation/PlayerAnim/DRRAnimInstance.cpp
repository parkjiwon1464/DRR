// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/PlayerAnim/DRRAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"


//Please bind Attack/Sitting key on bIsSit/bIsAttack

UDRRAnimInstance::UDRRAnimInstance()
{
	MoveThreadshold = 3.0f;	
}

void UDRRAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	Owner = Cast<ACharacter>(GetOwningActor());
	if (Owner)
	{
		Movement = Owner->GetCharacterMovement();
	}

}

void UDRRAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (Movement){
		GroundSpeed = Movement->Velocity.Size2D();
		bIsIdle = GroundSpeed < MoveThreadshold;

		bIsSit = Movement->IsCrouching();
	}
}
