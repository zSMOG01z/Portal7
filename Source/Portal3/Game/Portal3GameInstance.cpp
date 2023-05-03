// Fill out your copyright notice in the Description page of Project Settings.


#include "Portal3GameInstance.h"

FLevelData UPortal3GameInstance::GetStartupLevel() const
{
    return StartupLevel;
}

FLevelData UPortal3GameInstance::GetRandomLevel() const
{
    const auto CountLevels = LevelsData.Num();
    
    if (CountLevels > 1)
    {
        const auto RandomLevel = FMath::RandRange(0, CountLevels - 1);
        return LevelsData[RandomLevel];
    }
    else 
    if (CountLevels == 1)
    {
        return LevelsData[0];
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Levels is NONE"));
        return FLevelData();
    }
}

void UPortal3GameInstance::SetStartupLevel(const FLevelData& StartupLevelData)
{
    StartupLevel = StartupLevelData;
}

TArray<FLevelData> UPortal3GameInstance::GetLevelsData() const
{
    return LevelsData;
}

FName UPortal3GameInstance::GetMenuLevelName() const
{
    return MenuLevelName;
}

bool UPortal3GameInstance::GetSkipLearning()
{
    return bSkipLearning;
}

void UPortal3GameInstance::SetSkipLearning()
{
    bSkipLearning = true;
}
