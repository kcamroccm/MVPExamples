#include "MyWidget.h"
#include "MyPresenter.h"
#include "Kismet/KismetSystemLibrary.h"

void UMyWidget::NativeConstruct()
{
	Super::NativeConstruct();

	// -----------------------------------------------------------------
	//  1️⃣  Give each C++‑declared button a name that the presenter will
	//      recognise.  If you created the buttons purely in code, you can
	//      skip the SetName calls – the names you gave via SetName are
	//      the ones the presenter receives.
	// -----------------------------------------------------------------
	if (Btn_Start) { Btn_Start->SetName(FName(TEXT("Start"))); ButtonMap.Add(FName(TEXT("Start")), Btn_Start); }
	if (Btn_Options) { Btn_Options->SetName(FName(TEXT("Options"))); ButtonMap.Add(FName(TEXT("Options")), Btn_Options); }
	if (Btn_Quit) { Btn_Quit->SetName(FName(TEXT("Quit"))); ButtonMap.Add(FName(TEXT("Quit")), Btn_Quit); }

	// -----------------------------------------------------------------
	//  2️⃣  Bind a *single* click handler to every button.
	// -----------------------------------------------------------------
	for (auto It = ButtonMap.CreateConstIterator(); It; ++It)
	{
		UButton* B = It->Value;
		FName Name = It->Key;
		B->OnClicked.AddLambda([this, Name = Name]() {
			OnAnyButtonClicked(Name);
		});
	}
}

void UMyWidget::OnAnyButtonClicked(FName ButtonId)
{
	if (Presenter.IsValid())
		Presenter->OnButtonPressed(ButtonId);
	else
		UE_LOG(LogTemp, Warning, TEXT("MyWidget: presenter not bound."));
}

// -------------------------------------------------
// IMyViewInterface implementation
// -------------------------------------------------
void UMyWidget::SetStatusText(const FString& NewText)
{
	if (UTextBlock* TB = Cast<UTextBlock>(GetWidgetFromName(TEXT("StatusText"))))
		TB->SetText(FText::FromString(NewText));
	else
		UE_LOG(LogTemp, Warning, TEXT("MyWidget: missing StatusText widget."));
}

void UMyWidget::Refresh() { /* repopulate any lists, etc. */ }

void UMyWidget::RequestDestroy() { RemoveFromParent(); }

// -------------------------------------------------
// Public binding API
// -------------------------------------------------
void UMyWidget::BindPresenter(UMyPresenter* Presenter_)
{
	Presenter = Presenter_;
	// Example: instantly set a welcome text.
	SetStatusText(TEXT("Welcome!"));
}