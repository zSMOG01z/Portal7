// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_BaseWidget.h"
#include "C_PauseWidget.generated.h"

class UButton;

UCLASS()
class PORTAL3_API UC_PauseWidget : public UC_BaseWidget
{
	GENERATED_BODY()
	
	protected:
    UPROPERTY(meta = (BindWidget))
    UButton* UnpauseButton;

    virtual void NativeOnInitialized() override;

    private:
    UFUNCTION()
    void Unpause();
};
