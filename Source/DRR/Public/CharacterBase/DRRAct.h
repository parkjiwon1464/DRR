// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Interface/DRRActableInterface.h"
#include "DRRAct.generated.h"
DECLARE_DELEGATE(FActionDelegate);
/**
 * 
 */
UCLASS()
class DRR_API UDRRAct :public UObject
{
public:
	GENERATED_BODY()

	UDRRAct();
	
	void SetActor(class IDRRActableInterface* Target);
	virtual void ActRelease();
	const class UDA_ActData* GetCurAct();
	//���� �ൿ�� ���� �Է�
	virtual bool AfterAct();
	~UDRRAct();
	virtual float GetNextTime();
	virtual uint8 NextAct();
	//�Է¿� �ʿ伺�� ���� ��ȯ.�ൿ üũ �� ���� �ൿ�� �Է��� �ʿ����� ������������ ��ȯ.
	virtual bool NextReset();
	virtual uint8 GetCurFuncCount();
	FOnActFuncDelegate DoBeginAct();
	FOnActFuncDelegate DoAct();
	FOnActFuncDelegate DoEndAct();
	//�Է��� �ʿ伺������ ��ȯ. ��Ÿ, �޺��� ��� �Է��ؾ� ���� �ൿ�� ������ ����, ĳ��Ʈ�� ���� �Է��� �ʿ���� ���� �Է��� ������ �ൿ�� �����.
	virtual bool BeginAct();
	virtual FName GetMontgeSectionName();
	virtual void EndAct();
	FOnActCheckConditionDelegate GetConditionCheckFunc() { return ConditionCheckFunc; }

protected:
	
private:
	void SetActs(class IDRRActableInterface* Target);
	virtual void BeginDestroy() override;
protected:

	FOnActFuncDelegate BeginActFunc;
	FOnActFuncDelegate EndActFunc;
	FOnActCheckConditionDelegate ConditionCheckFunc;
	TArray<FOnActFuncDelegate> ActFunc;
	uint8 curActCount;
	uint8 curFuncCount;
	TObjectPtr<class UDA_ActData> CurAct;
	

};


