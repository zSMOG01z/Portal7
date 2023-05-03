// Fill out your copyright notice in the Description page of Project Settings.

#include "C_EndLevelWidget.h"
#include "Portal3/Game/Portal3GameInstance.h"
#include "Portal3/Portal3GameMode.h"

#include "GameFramework/GameModeBase.h"
#include "Components/Button.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"

void UC_EndLevelWidget::NativeOnInitialized()
{
    Super::NativeOnInitialized();

    if (!GetRewardButton)
    {
        return;
    }
    GetRewardButton->OnClicked.AddDynamic(this, &UC_EndLevelWidget::GetReward);

    if (!SecretButton)
    {
        return;
    }
    SecretButton->OnClicked.AddDynamic(this, &UC_EndLevelWidget::GetSecret);

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

void UC_EndLevelWidget::OnAnimationFinished_Implementation(const UWidgetAnimation* Animation)
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
    if (bIsLoose)
    {
        UGameplayStatics::OpenLevel(this, Portal3GameInstatnce->GetRandomLevel().LevelName);
    }
    else
    {
        if (!GetWorld() 
            || !GetWorld()->GetGameInstance() 
            || !GetWorld()->GetAuthGameMode())
        {
            return;
        }

        const auto GameInstance = Cast<UPortal3GameInstance>(GetWorld()->GetGameInstance());
        if (!GameInstance)
        {
            return;
        }
        const auto GameMode = Cast<APortal3GameMode>(GetWorld()->GetAuthGameMode());
        GameMode->Win();
    }
}

void UC_EndLevelWidget::GetReward()
{
    bIsLoose = true;
    PlayAnimation(HideAnimation);
}

void UC_EndLevelWidget::GetSecret()
{
    bIsLoose = false;
    PlayAnimation(HideAnimation);
}
