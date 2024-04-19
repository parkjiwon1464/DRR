// Fill out your copyright notice in the Description page of Project Settings.


#include "Skill/Skills/DRRShortShotActUnitProto.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/Character.h"
#include "Engine/DamageEvents.h"


#include "Utilities/CLog.h"


UDRRShortShotActUnitProto::UDRRShortShotActUnitProto()
{
	ConstructorHelpers::FObjectFinder<UDA_ActData> DataAssetRef(TEXT("/Script/DRR.DA_ShortShotActData'/Game/Blueprints/Weapon/Weapon1/DA_ShortShotWeaponAct1.DA_ShortShotWeaponAct1'"));
	if (DataAssetRef.Object)
	{
		ActData = DataAssetRef.Object;
	}
	CLog::Log("ActDataCheck");
	CLog::Log(ActData != nullptr);
	CLog::Log(ActData->ActionName);
	
}

TArray<FOnActFuncDelegate> UDRRShortShotActUnitProto::GetActFunc()
{
	TArray<FOnActFuncDelegate> arr;

	FOnActFuncDelegate temp;
	temp.BindUObject(this, &UDRRShortShotActUnitProto::Func1);
	arr.Add(temp);
	return arr;
}

void UDRRShortShotActUnitProto::BeginFunc(AActor* Owner)
{
	CLog::Log("ActBeginFunc");
}

void UDRRShortShotActUnitProto::EndFunc(AActor* Owner)
{
	CLog::Log("ActEndFunc");
}

void UDRRShortShotActUnitProto::Func1(AActor* Owner)
{
	CLog::Log("DamageTestActFunc1");

	ACharacter* User = Cast<ACharacter>(Owner);

	UE_LOG(LogTemp, Log, TEXT("AttackHitCheck"));


	//�浹�� �̸��� ����,������ ����:this�� �־� �ڽ��� �浹�Ǵ°� ����
	FCollisionQueryParams collisionParams(SCENE_QUERY_STAT(Attack), false, User);

	FHitResult outHitResult;
	TArray<FHitResult> outHitResults;
	TArray<FOverlapResult> outOverlapResults;
	const float attackRange = 150.0f;
	const float capsuleRadius = 50.0f;
	bool isHit;

	//������ ���� ��ġ, ������ �������, ĸ��������Ʈ�� ������ũ��
	const FVector start = User->GetActorLocation() + User->GetActorForwardVector() * User->GetCapsuleComponent()->GetScaledCapsuleRadius();
	
	FVector end;


	//ĸ���� �߾���ġ
	FVector capsulePosition = start + (end - start) / 2.0f;

	float halfHeight = attackRange / 2.0f;

	end = start + User->GetActorForwardVector() * attackRange;
	isHit = GetWorld()->SweepSingleByChannel(outHitResult, start, end, FQuat::Identity, ECC_GameTraceChannel1, FCollisionShape::MakeSphere(capsuleRadius * 2), collisionParams);

	//DebugDraw
	bool isRemaining = false;
	FColor Color = isHit ? FColor::Green : FColor::Red;
	DrawDebugCapsule(GetWorld(), end, halfHeight, capsuleRadius * 2, FRotationMatrix::MakeFromZ(User->GetActorForwardVector()).ToQuat(), Color, isRemaining, 3.0f);

	

	
	if (isHit)
	{

		FDamageEvent damageEvent;
		CLog::Log("Hitted");
		//�浹����� ���� ������ ���ظ� ������ �Լ� ȣ��
		//�𸮾󿡼� ������ ��� ���͵��� �������� �Դ´ٴ� �����Ͽ� �����Լ�
		//����, �̺�Ʈ, ������Ʈ�ѷ�,������ ����

		if (outHitResult.GetActor())
		{

			outHitResult.GetActor()->TakeDamage(40.0f, damageEvent, User->GetController(), User);
		}
	}

	//��ο� ����� ������ �����϶���
	//����� �� �ڵ带 ����Ҷ� ������ ���� �ʵ��� �׽�Ʈ�� ���忡���� �۵��ϰ���


}
