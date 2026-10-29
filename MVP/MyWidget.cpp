#include "MyWidget.h"
#include "MyPresenter.h"
#include "Kismet/KismetSystemLibrary.h"

void UMyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// Walk the widget tree, find every UButton, and bind a single click
	// handler that forwards the button's designer name.
	for (UWidget* W : WidgetTree->GetAllWidgets())
	{
		UButton* B = Cast<UButton>(W);
		if (!B) continue;

		FName btnName = FName(*B->GetFName());
		ButtonMap.Add(btnName, B);

		// One delegate for ALL buttons – captures the name.
		B->OnClicked.AddLambda([this, Name = btnName]() {
			OnAnyButtonClicked(Name);
		});
	}
}

void UMyWidget::OnAnyButtonClicked(FName ButtonId)
{
	if (Presenter.IsValid())
	{
		Presenter->OnButtonPressed(ButtonId);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MyWidget: presenter not bound when button clicked."));
	}
}

// -------------------------------------------------
//  IMyViewInterface implementation
// -------------------------------------------------
void UMyWidget::SetStatusText(const FString& NewText)
{
	if (UTextBlock* TB = Cast<UTextBlock>(GetWidgetFromName(TEXT("StatusText"))))
	{
		TB->SetText(FText::FromString(NewText));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("MyWidget: could not find StatusText widget."));
	}
}

void UMyWidget::Refresh()
{
	// Repopulate lists, etc. – left empty for this demo.
}

void UMyWidget::RequestDestroy()
{
	RemoveFromParent();
}

// -------------------------------------------------
//  Public binding API
// -------------------------------------------------
void UMyWidget::BindPresenter(UMyPresenter* Presenter_)
{
	Presenter = Presenter_; // weak – no ownership.
	// Example: instantly set a welcome text.
	SetStatusText(TEXT("Welcome to the demo!"));
}