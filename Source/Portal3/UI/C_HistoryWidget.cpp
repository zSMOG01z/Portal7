// Fill out your copyright notice in the Description page of Project Settings.

#include "C_HistoryWidget.h"
#include "Portal3/Portal3GameMode.h"
#include "Portal3/Game/Portal3GameInstance.h"

#include "Components/Button.h"

void UC_HistoryWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!StartGameButton)
    {
        return;
    }
    StartGameButton->OnClicked.AddDynamic(this, &UC_HistoryWidget::StartGame);

    if (!GetWorld()->GetGameInstance())
    {
        return;
    }
    const auto GameInstance = Cast<UPortal3GameInstance>(GetWorld()->GetGameInstance());
    GetWorld()->GetFirstPlayerController()->SetPause(true);
}

void UC_HistoryWidget::StartGame()
{
    if (!GetWorld() 
        || !GetWorld()->GetAuthGameMode())
    {
        return;
    }
    GetWorld()->GetAuthGameMode()->ClearPause();

    PlaySpeechInterruptionSound();

    const auto GameMode = Cast<APortal3GameMode>(GetWorld()->GetAuthGameMode());
    if (!GameMode)
    {
        return;
    }
    GameMode->Game();
}
