// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DRRPassiveActableInterface.generated.h"

DECLARE_DELEGATE(FOnPassiveFuncDelegate)
// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UDRRPassiveActableInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class DRR_API IDRRPassiveActableInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	virtual FOnPassiveFuncDelegate GetBeginPassiveFunc() = 0;
	virtual FOnPassiveFuncDelegate GetClearPassiveFunc() = 0;
	virtual FOnPassiveFuncDelegate GetEndPassiveFunc() = 0;
	virtual class UDRRPassiveData* GetPassiveData() = 0;
};
