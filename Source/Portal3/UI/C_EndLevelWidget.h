// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "C_BaseWidget.h"
#include "C_EndLevelWidget.generated.h"

class UButton;

UCLASS()
class PORTAL3_API UC_EndLevelWidget : public UC_BaseWidget
{
	GENERATED_BODY()
	
	protected:
    UPROPERTY(meta = (BindWidget))
    UButton* GetRewardButton;

    UPROPERTY(meta = (BindWidget))
    UButton* SecretButton;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* HideAnimation;

    virtual void NativeOnInitialized() override;
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);

private:
    bool bIsLoose = true;
    UFUNCTION()
    void GetReward();
    UFUNCTION()
    void GetSecret();
};
