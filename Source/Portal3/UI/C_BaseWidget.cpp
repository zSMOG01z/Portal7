// Fill out your copyright notice in the Description page of Project Settings.


#include "C_BaseWidget.h"
#include "Portal3/Portal3Character.h"

#include "Components/AudioComponent.h"
#include "GameFramework/GameModeBase.h"

void UC_BaseWidget::NativeOnInitialized()
{
    if (!GetWorld() 
        || !GetWorld()->GetFirstPlayerController() 
        || !GetWorld()->GetFirstPlayerController()->GetCharacter())
    {
        return;
    }
    const auto PlayerCharecter = Cast<APortal3Character>(GetWorld()->GetFirstPlayerController()->GetCharacter());
    AudioComponent = Cast<UAudioComponent>(PlayerCharecter->GetComponentByClass(UAudioComponent::StaticClass()));
    AudioComponent->bIsUISound = true;
    AudioComponent->bAutoActivate = false;
    OnNativeVisibilityChanged.AddUObject(this, &UC_BaseWidget::NativeVisibilityChanged);
}

void UC_BaseWidget::Show()
{
    PlayAnimation(ShowAnimation);
}

void UC_BaseWidget::PlaySpeechSound()
{
    if (SpeechSound)
    {
        AudioComponent->SetSound(SpeechSound);
        AudioComponent->Play();
    }
}

void UC_BaseWidget::PlaySpeechInterruptionSound()
{
    if (SpeechSound 
        && SpeechInterruptionSound)
    {
        if (AudioComponent->IsActive())
        {
            AudioComponent->SetSound(SpeechInterruptionSound);
            AudioComponent->Play();
        }
    }
}

void UC_BaseWidget::NativeVisibilityChanged(ESlateVisibility SlateVisibility)
{
    if (SlateVisibility == ESlateVisibility::Visible)
    {
        PlaySpeechSound();
    }
}
