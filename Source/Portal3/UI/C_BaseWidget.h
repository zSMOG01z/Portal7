// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "C_BaseWidget.generated.h"

UCLASS()
class PORTAL3_API UC_BaseWidget : public UUserWidget
{
	GENERATED_BODY()
	
	public:
    virtual void NativeOnInitialized() override;
    void Show();

	protected:
    UPROPERTY(meta = (BindWidgetAnim), Transient)
    UWidgetAnimation* ShowAnimation;
    // Audio
    protected:
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
    USoundBase* SpeechSound;
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Audio)
    USoundBase* SpeechInterruptionSound;

    UFUNCTION()
    void PlaySpeechSound();
    UFUNCTION()
    void PlaySpeechInterruptionSound();
    void NativeVisibilityChanged(ESlateVisibility SlateVisibility);

    private:
    UAudioComponent* AudioComponent;
};
