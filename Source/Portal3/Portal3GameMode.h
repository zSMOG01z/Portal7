// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameFunctionLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "Portal3GameMode.generated.h"

UCLASS(minimalapi)
class APortal3GameMode : public AGameMode
{
	GENERATED_BODY()

    public:
    APortal3GameMode();

	FOnGameStateChangedSignature OnGameStateChanged;

    virtual void StartPlay() override;


    virtual UClass* GetDefaultPawnClassForController_Implementation(AController* InController) override;

	virtual bool SetPause(APlayerController* PC, FCanUnpause CanUnpauseDelegate = FCanUnpause()) override;
    virtual bool ClearPause() override;
    UFUNCTION(BlueprintCallable)
    void StartLevel();
    UFUNCTION(BlueprintCallable)
    void EndLevel();
    UFUNCTION(BlueprintCallable)
    void Win();
    UFUNCTION(BlueprintCallable)
    void Loose();
    UFUNCTION(BlueprintCallable)
    void History();
    UFUNCTION(BlueprintCallable)
    void Game();

	private:
    EGameState GameState = EGameState::Game;
    void SetGameState(EGameState State);
};



