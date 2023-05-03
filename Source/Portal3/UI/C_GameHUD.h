// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Portal3/FunctionLibraries/GameFunctionLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "C_GameHUD.generated.h"

class UC_BaseWidget;

UCLASS()
class PORTAL3_API AC_GameHUD : public AHUD
{
	GENERATED_BODY()
	
    public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> StartLevelWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> EndLevelWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> HistoryWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> PauseWidgetClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> WinWidgetClass;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI")
    TSubclassOf<UUserWidget> GameWidgetClass;

	virtual void BeginPlay() override;

	private:
    UPROPERTY()
    TMap<EGameState, UC_BaseWidget*> GameWidgets;
    UPROPERTY()
    UC_BaseWidget* CurrentWidget = nullptr;

    void OnGameStateChanged(EGameState State);
    void HideCurrentWidget();
    void ShowStateWidget(EGameState State);
};
