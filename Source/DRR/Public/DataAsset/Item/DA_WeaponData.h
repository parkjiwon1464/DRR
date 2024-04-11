// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DataAsset/Item/DA_UseableData.h"
#include "DA_WeaponData.generated.h"

/**
 * 
 */
UCLASS()
class DRR_API UDA_WeaponData : public UDA_ItemData
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, Category = weapon)
	// TSoftObjectPtr�ε��� �̷�� ���߿� �ʿ��Ҷ� �ε�
	TSoftObjectPtr<class USkeletalMesh> WeaponMesh;
	
	//�ִ� �ν��Ͻ��� �߰�
	TObjectPtr<class UAnimInstance> Anim;



};
