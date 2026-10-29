#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "IMyViewInterface.h"
#include "MyWidget.generated.h"

UCLASS()
class UMyWidget : public UUserWidget, public IMyViewInterface
{
	GENERATED_BODY()

public:
	virtual void NativeConstruct() override;

	// -------------------------------------------------
	//  IMyViewInterface implementation
	// -------------------------------------------------
	virtual void SetStatusText(const FString& NewText) override;
	virtual void Refresh() override;
	virtual void RequestDestroy() override;

	// -------------------------------------------------
	//  Public API for binding the presenter.
	// -------------------------------------------------
	UFUNCTION(BlueprintCallable, Category = "Binding")
	void BindPresenter(UMyPresenter* Presenter);

private:
	// -------------------------------------------------
	//  One lambda forwards the button's designer name.
	// -------------------------------------------------
	UFUNCTION()
	void OnAnyButtonClicked(FName ButtonId);

	// Weak ref back to presenter (optional)
	TWeakObjectPtr<UMyPresenter> Presenter;

	// -------------------------------------------------
	//  Buttons that we create in C++.
	//  The meta=(BindWidget) makes the editor create the object
	//  and assign it to this pointer automatically.
	// -------------------------------------------------
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Start;
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Options;
	UPROPERTY(meta = (BindWidget)) UButton* Btn_Quit;

	// A helper map for debugging (optional)
	TMap<FName, UButton*> ButtonMap;
};