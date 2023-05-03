// Fill out your copyright notice in the Description page of Project Settings.

#include "C_Portal3PlayerController.h"
#include "Portal3/Portal3GameMode.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AC_Portal3PlayerController::AC_Portal3PlayerController()
{
    CreateMappingContext();
}

void AC_Portal3PlayerController::BeginPlay()
{
    Super::BeginPlay();

    if (!GetWorld())
    {
        return;
    }

    const auto GameMode = Cast<APortal3GameMode>(GetWorld()->GetAuthGameMode());
    if (!GameMode)
    {
        return;
    }
    GameMode->OnGameStateChanged.AddUObject(this, &AC_Portal3PlayerController::OnGameStateChanged);
}

void AC_Portal3PlayerController::SetupInputComponent()
{
    Super::SetupInputComponent();

    UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
    if (!EnhancedInputComponent)
    {
        return;
    }
    EnhancedInputComponent->BindAction(GamePauseAction, ETriggerEvent::Triggered, this, &AC_Portal3PlayerController::OnGamePause);
}

void AC_Portal3PlayerController::CreateMappingContext()
{
    UEnhancedInputLocalPlayerSubsystem* EnhancedInputSubsystem =
        ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
    if (!EnhancedInputSubsystem)
    {
        return;
    }

    EnhancedInputSubsystem->AddMappingContext(PlayerMappingContext, 0);
}

void AC_Portal3PlayerController::OnGamePause()
{
    if (!GetWorld() 
        || !GetWorld()->GetAuthGameMode())
    {
        return;
    }

    GetWorld()->GetAuthGameMode()->SetPause(this);
}

void AC_Portal3PlayerController::OnGameStateChanged(EGameState State)
{
    if (State == EGameState::Game)
    {
        SetInputMode(FInputModeGameOnly());
        bShowMouseCursor = false;
    }
    else
    {
        SetInputMode(FInputModeUIOnly());
        bShowMouseCursor = true;
    }
}
