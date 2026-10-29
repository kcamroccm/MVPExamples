#include "MyPresenter.h"
#include "Widgets/MyWidget.h"

void UMyPresenter::SetView(IMyViewInterface* V)
{
	View = V; // weak reference – GC safe
}

void UMyPresenter::SetStatusText(const FString& NewText)
{
	if (View.IsValid())
	{
		View->SetStatusText(NewText);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Presenter: view not set when trying to set status text."));
	}
}

void UMyPresenter::Refresh()
{
	if (View.IsValid())
	{
		View->Refresh();
	}
}

void UMyPresenter::RequestViewDestroy()
{
	if (View.IsValid())
	{
		View->RequestDestroy();
	}
}

// -----------------------------------------------------------------
//  Called by the widget when any button is clicked.
// -----------------------------------------------------------------
void UMyPresenter::OnButtonPressed(FName ButtonId)
{
	// Single place to react to every button.
	switch (ButtonId.ToString())
	{
		case TEXT("Start"):
			// e.g. StartGame();
			break;
		case TEXT("Options"):
			// e.g. OpenOptionsMenu();
			break;
		case TEXT("Quit"):
			// e.g. UGameplayStatics::OpenLevel(this, TEXT("MainMenu"));
			break;
		default:
			// Unknown button – could log a warning.
			break;
	}
}