// Fill out your copyright notice in the Description page of Project Settings.

#include "C_MenuWidget.h"
#include "Portal3/Game/Portal3GameInstance.h"

#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UC_MenuWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (StartGameButton)
    {
        StartGameButton->OnClicked.AddDynamic(this, &UC_MenuWidget::OnStartGame);
    }

    if (QuitGameButton)
    {
        QuitGameButton->OnClicked.AddDynamic(this, &UC_MenuWidget::OnQuitGame);
    }
    PlaySpeechSound();
}

void UC_MenuWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
{
    if (Animation != HideAnimation 
        || !GetWorld())
    {
        return;
    }
    const auto Portal3GameInstatnce = GetWorld()->GetGameInstance<UPortal3GameInstance>();
    if (!Portal3GameInstatnce)
    {
        return;
    }
    const auto RandomLevelName = Portal3GameInstatnce->GetRandomLevel().LevelName;
    UE_LOG(LogTemp, Error, TEXT("Level %s loading"), *RandomLevelName.ToString());
    UGameplayStatics::OpenLevel(this, RandomLevelName);
}

void UC_MenuWidget::OnStartGame()
{
    PlayAnimation(HideAnimation);
}

void UC_MenuWidget::OnQuitGame()
{
    UKismetSystemLibrary::QuitGame(this, GetOwningPlayer(), EQuitPreference::Quit, true);
}
