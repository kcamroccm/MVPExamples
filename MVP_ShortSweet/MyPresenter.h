#pragma once

#include "CoreMinimal.h"
#include "Widgets/MyWidget.h"
#include "MyPresenter.generated.h"

UCLASS()
class UMyPresenter : public UObject
{
    GENERATED_BODY()

public:
    UMyPresenter() = default;

    UFUNCTION(BlueprintCallable, Category = "Setup")
    void SetView(UMyWidget* View);

    UFUNCTION(BlueprintCallable, Category = "Actions")
    void OnStart();

    UFUNCTION(BlueprintCallable, Category = "Actions")
    void OnOptions();

    UFUNCTION(BlueprintCallable, Category = "Actions")
    void OnQuit();

private:
    TWeakObjectPtr<UMyWidget> View;
};