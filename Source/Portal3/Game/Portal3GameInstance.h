// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameFunctionLibrary.h"

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Portal3GameInstance.generated.h"

UCLASS()
class PORTAL3_API UPortal3GameInstance : public UGameInstance
{
	GENERATED_BODY()
	
	public:
    FLevelData GetStartupLevel() const;
    FLevelData GetRandomLevel() const;
    void SetStartupLevel(const FLevelData& StartupLevelData);
    TArray<FLevelData> GetLevelsData() const;
    FName GetMenuLevelName() const;
    void SetSkipLearning();
    bool GetSkipLearning();

    protected:
    UPROPERTY(EditDefaultsOnly, Category = "Game")
    TArray<FLevelData> LevelsData;

    UPROPERTY(EditDefaultsOnly, Category = "Game", meta = (ToolTip = "Lavel names must be unique!"))
    FName MenuLevelName = NAME_None;

    private:
    FLevelData StartupLevel;
    bool bSkipLearning = false;
};
