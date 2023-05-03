// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFunctionLibrary.h"
#include "Portal3\UI\C_BaseWidget.h"

#include "CoreMinimal.h"
#include "C_MenuWidget.generated.h"

class UButton;

UCLASS()
class PORTAL3_API UC_MenuWidget : public UC_BaseWidget
{
	GENERATED_BODY()
	
	protected:
    UPROPERTY(meta = (BindWidget))
    UButton* StartGameButton;

    UPROPERTY(meta = (BindWidget))
    UButton* QuitGameButton;

    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* HideAnimation;

    virtual void NativeOnInitialized() override;
    virtual void OnAnimationFinished_Implementation(const UWidgetAnimation* Animation);

private:
    UFUNCTION()
    void OnStartGame();

    UFUNCTION()
    void OnQuitGame();
};
