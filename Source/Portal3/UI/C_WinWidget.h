// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Portal3/FunctionLibraries/GameFunctionLibrary.h"

#include "CoreMinimal.h"
#include "C_BaseWidget.h"
#include "C_WinWidget.generated.h"

class UButton;

UCLASS()
class PORTAL3_API UC_WinWidget : public UC_BaseWidget
{
	GENERATED_BODY()

    protected:
    UPROPERTY(meta = (BindWidget))
    UButton* WinButton;

    virtual void NativeOnInitialized() override;

    private:
    UFUNCTION()
    void Win();
};
