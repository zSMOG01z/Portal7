// Fill out your copyright notice in the Description page of Project Settings.

#include "C_PauseWidget.h"

#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

void UC_PauseWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!UnpauseButton)
    {
        return;
    }
    UnpauseButton->OnClicked.AddDynamic(this, &UC_PauseWidget::Unpause);
}

void UC_PauseWidget::Unpause()
{
    if (!GetWorld() && !GetWorld()->GetAuthGameMode())
    {
        return;
    }
    GetWorld()->GetAuthGameMode()->ClearPause();

    PlaySpeechInterruptionSound();
}
