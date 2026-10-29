#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "MyWidget.generated.h"

UCLASS()
class UMyWidget : public UUserWidget
{
    GENERATED_BODY()

public:
    virtual void NativeConstruct() override;

    UFUNCTION(BlueprintCallable, Category = "Presentation")
    void SetStatus(const FString& NewText);

    UFUNCTION(BlueprintCallable, Category = "Presentation")
    void Refresh();

    UFUNCTION(BlueprintCallable, Category = "Presentation")
    void RequestDestroy();

    UPROPERTY(meta = (BindWidget)) UButton* Btn_Start;
    UPROPERTY(meta = (BindWidget)) UButton* Btn_Options;
    UPROPERTY(meta = (BindWidget)) UButton* Btn_Quit;

    TWeakObjectPtr<class UMyPresenter> Presenter;
};