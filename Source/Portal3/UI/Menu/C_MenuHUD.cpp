// Fill out your copyright notice in the Description page of Project Settings.


#include "C_MenuHUD.h"
#include "Portal3/UI/C_BaseWidget.h"

void AC_MenuHUD::BeginPlay()
{
    Super::BeginPlay();

    if (!GetWorld() || !MenuWidgetClass)
    {
        return;
    }

    const auto MenuWidget = CreateWidget<UC_BaseWidget>(GetWorld(), MenuWidgetClass);
    if (!MenuWidget)
    {
        return;
    }
    MenuWidget->Show();
    MenuWidget->AddToViewport();
}
