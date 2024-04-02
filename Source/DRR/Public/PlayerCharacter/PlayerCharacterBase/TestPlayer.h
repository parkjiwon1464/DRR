// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interface/DRRActorInterface.h"
#include "TestPlayer.generated.h"

UCLASS()
class DRR_API ATestPlayer : public ACharacter, public IDRRActorInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATestPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetWeapon(TSubclassOf<class ADRRWeaponBase> NewWeapon);

	virtual void WeaponLeftAttackPress();
	virtual void WeaponRightAttackPress();
	virtual void WeaponLeftAttackRelaease();
	virtual void WeaponRightAttackRelaease();

	//�߰� ����2
	virtual void Act() override;

protected:


	//�ൿ ������Ʈ. �߰�����1
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = Act, Meta = (AllowPrivateAccess = "true"));
	TObjectPtr<class UDRRActComponent> ActComponent;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Weapon, Meta = (AllowPrivateAccess = "true"));
	TSubclassOf<class ADRRWeaponBase> Weapon;

	//UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = Weapon, Meta = (AllowPrivateAccess = "true"));
	//TObjectPtr<class ADRRWeaponBase> WeaponObject;

	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Equipment, Meta = (AllowPrivateAccess = "true"))
	//TObjectPtr<class USkeletalMeshComponent> WeaponMesh;


	//��ǲ�������ý�Ʈ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputMappingContext> defaultMappingContext;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ActLeftPressAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ActLeftReleaseAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ActRightPressAction;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, Meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UInputAction> ActRightReleaseAction;
};
