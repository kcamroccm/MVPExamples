#pragma once

#include "CoreMinimal.h"
#include "Widgets/IMyViewInterface.h"
#include "MyPresenter.generated.h"

UCLASS()
class UMyPresenter : public UObject
{
	GENERATED_BODY()

public:
	UMyPresenter() = default;

	UFUNCTION(BlueprintCallable, Category = "Presentation")
	void SetView(IMyViewInterface* View);

	UFUNCTION(BlueprintCallable, Category = "Presentation")
	void SetStatusText(const FString& NewText);

	UFUNCTION(BlueprintCallable, Category = "Presentation")
	void Refresh();

	UFUNCTION(BlueprintCallable, Category = "Presentation")
	void RequestViewDestroy();

	UFUNCTION(BlueprintCallable, Category = "Presentation")
	virtual void OnButtonPressed(FName ButtonId);

private:
	/** Weak reference – does NOT keep the widget alive. */
	TWeakObjectPtr<IMyViewInterface> View;
};