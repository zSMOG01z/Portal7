// Fill out your copyright notice in the Description page of Project Settings.

#include "C_GameHUD.h"
#include "C_BaseWidget.h"
#include "Portal3/Portal3GameMode.h"

void AC_GameHUD::BeginPlay()
{
    Super::BeginPlay();

    GameWidgets.Add(EGameState::StartLevel, CreateWidget<UC_BaseWidget>(GetWorld(), StartLevelWidgetClass));
    GameWidgets.Add(EGameState::EndLevel, CreateWidget<UC_BaseWidget>(GetWorld(), EndLevelWidgetClass));
    GameWidgets.Add(EGameState::History, CreateWidget<UC_BaseWidget>(GetWorld(), HistoryWidgetClass));
    GameWidgets.Add(EGameState::Pause, CreateWidget<UC_BaseWidget>(GetWorld(), PauseWidgetClass));
    GameWidgets.Add(EGameState::Win, CreateWidget<UC_BaseWidget>(GetWorld(), WinWidgetClass));
    GameWidgets.Add(EGameState::Game, CreateWidget<UC_BaseWidget>(GetWorld(), GameWidgetClass));

    for (auto GameWidgetPair : GameWidgets)
    {
        const auto GameWidget = GameWidgetPair.Value;
        if (!GameWidget)
        {
            continue;
        }
        GameWidget->AddToViewport();
        GameWidget->SetVisibility(ESlateVisibility::Hidden);
    }

    if (!GetWorld())
    {
        return;
    }

    const auto GameMode = Cast<APortal3GameMode>(GetWorld()->GetAuthGameMode());
    if (!GameMode)
    {
        return;
    }
    GameMode->OnGameStateChanged.AddUObject(this, &AC_GameHUD::OnGameStateChanged);
}

void AC_GameHUD::OnGameStateChanged(EGameState State)
{
    HideCurrentWidget();
    ShowStateWidget(State);
}

void AC_GameHUD::HideCurrentWidget()
{
    if (!CurrentWidget)
    {
        return;
    }
    CurrentWidget->SetVisibility(ESlateVisibility::Hidden);
}

void AC_GameHUD::ShowStateWidget(EGameState State)
{
    const auto ContainsWidget = GameWidgets.Contains(State);
    if (ContainsWidget)
    {
        CurrentWidget = GameWidgets[State];
    }

    if (!CurrentWidget)
    {
        return;
    }
    CurrentWidget->SetVisibility(ESlateVisibility::Visible);
    CurrentWidget->Show();
}
