// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "Portal3/FunctionLibraries/GameFunctionLibrary.h"

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "C_Portal3PlayerController.generated.h"

class UInputMappingContext;

UCLASS()
class PORTAL3_API AC_Portal3PlayerController : public APlayerController
{
	GENERATED_BODY()
	
	public:
    AC_Portal3PlayerController();

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    class UInputAction* GamePauseAction;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
    UInputMappingContext* PlayerMappingContext;

    virtual void BeginPlay() override;
    virtual void SetupInputComponent() override;
    void CreateMappingContext();

private:
    void OnGamePause();
    void OnGameStateChanged(EGameState State);
};
