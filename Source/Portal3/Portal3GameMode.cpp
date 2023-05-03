// Copyright Epic Games, Inc. All Rights Reserved.

#include "Portal3GameMode.h"
#include "Portal3Character.h"
#include "Player/C_Portal3PlayerController.h"
#include "UI/C_GameHUD.h"

#include "UObject/ConstructorHelpers.h"

APortal3GameMode::APortal3GameMode()
{
    PlayerControllerClass = AC_Portal3PlayerController::StaticClass();
    DefaultPawnClass = APortal3Character::StaticClass();
    HUDClass = AC_GameHUD::StaticClass();
}

void APortal3GameMode::StartPlay()
{
    Super::StartPlay();

    StartLevel();
}

UClass* APortal3GameMode::GetDefaultPawnClassForController_Implementation(AController* InController)
{
    return Super::GetDefaultPawnClassForController_Implementation(InController);
}

bool APortal3GameMode::SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate)
{
    const auto PauseSet = Super::SetPause(PC, CanUnpauseDelegate);
    if (PauseSet)
    {
        SetGameState(EGameState::Pause);
    }

    return PauseSet;
}

bool APortal3GameMode::ClearPause()
{
    const auto Unpaused = Super::ClearPause();
    if (Unpaused)
    {
        SetGameState(EGameState::Game);
    }

    return Unpaused;
}

void APortal3GameMode::History()
{
    UE_LOG(LogTemp, Warning, TEXT("========== HISTORY =========="));
    SetGameState(EGameState::History);
}

void APortal3GameMode::Game()
{
    UE_LOG(LogTemp, Warning, TEXT("========== GAME =========="));
    SetGameState(EGameState::Game);
}

void APortal3GameMode::StartLevel()
{
    UE_LOG(LogTemp, Warning, TEXT("========== START LEVEL =========="));
    SetGameState(EGameState::StartLevel);
}

void APortal3GameMode::EndLevel()
{
    UE_LOG(LogTemp, Warning, TEXT("========== END LEVEL =========="));
    SetGameState(EGameState::EndLevel);
}

void APortal3GameMode::Loose()
{
    UE_LOG(LogTemp, Warning, TEXT("========== LOOSE =========="));

}

void APortal3GameMode::Win()
{
    UE_LOG(LogTemp, Warning, TEXT("========== WIN =========="));
    SetGameState(EGameState::Win);
}

void APortal3GameMode::SetGameState(EGameState State)
{
    if (GameState == State)
    {
        return;
    }

    GameState = State;
    OnGameStateChanged.Broadcast(GameState);
}
