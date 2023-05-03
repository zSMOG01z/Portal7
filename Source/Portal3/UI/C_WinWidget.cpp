// Fill out your copyright notice in the Description page of Project Settings.

#include "C_WinWidget.h"
#include "Portal3/Game/Portal3GameInstance.h"

#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

void UC_WinWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!WinButton)
    {
        return;
    }
    WinButton->OnClicked.AddDynamic(this, &UC_WinWidget::Win);

    if (!GetWorld() && !GetWorld()->GetGameInstance())
    {
        return;
    }
    const auto GameInstance = Cast<UPortal3GameInstance>(GetWorld()->GetGameInstance());
    if (GameInstance->GetSkipLearning())
    {
        GetWorld()->GetFirstPlayerController()->SetPause(true);
    }
}

void UC_WinWidget::Win()
{
    if (!GetWorld())
    {
        return;
    }
    const auto STUGameInstatnce = GetWorld()->GetGameInstance<UPortal3GameInstance>();
    if (!STUGameInstatnce)
    {
        return;
    }
    if (STUGameInstatnce->GetMenuLevelName().IsNone())
    {
        UE_LOG(LogTemp, Error, TEXT("Menu level name is NONE"));
        return;
    }

    UGameplayStatics::OpenLevel(this, STUGameInstatnce->GetMenuLevelName());
}

