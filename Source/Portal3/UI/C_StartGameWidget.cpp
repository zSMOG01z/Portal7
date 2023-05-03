// Fill out your copyright notice in the Description page of Project Settings.

#include "C_StartGameWidget.h"
#include "Portal3/Game/Portal3GameInstance.h"
#include "Portal3/Portal3GameMode.h"

#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"

void UC_StartGameWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!StartGameButton)
    {
        return;
    }
    StartGameButton->OnClicked.AddDynamic(this, &UC_StartGameWidget::StartGame);

    if (!GetWorld() 
        && !GetWorld()->GetGameInstance())
    {
        return;
    }
    const auto GameInstance = Cast<UPortal3GameInstance>(GetWorld()->GetGameInstance());
    if (GameInstance->GetSkipLearning())
    {
        GetWorld()->GetFirstPlayerController()->SetPause(true);
    }
}

void UC_StartGameWidget::StartGame()
{
    if (!GetWorld() 
        || !GetWorld()->GetGameInstance() 
        || !GetWorld()->GetAuthGameMode())
    {
        return;
    }

    PlaySpeechInterruptionSound();

    const auto GameInstance = Cast<UPortal3GameInstance>(GetWorld()->GetGameInstance());
    if (!GameInstance->GetSkipLearning())
    {
        GameInstance->SetSkipLearning();

        const auto GameMode = Cast<APortal3GameMode>(GetWorld()->GetAuthGameMode());
        GameMode->History();
    }
    else
    {
        GetWorld()->GetAuthGameMode()->ClearPause();
    }
}
