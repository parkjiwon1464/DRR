// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "DRRMainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class DRR_API ADRRMainGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ADRRMainGameMode();

	virtual void BeginPlay() override;

	FORCEINLINE UUserWidget* GetMainHUDWidget() { return MainHUDWidget; }

protected:
	UPROPERTY()
	TSubclassOf<UUserWidget> MainHUDWidgetClass;

	UPROPERTY()
	UUserWidget* MainHUDWidget;

private:
	UPROPERTY()
	class UDataTable* ItemDataTable;
};
