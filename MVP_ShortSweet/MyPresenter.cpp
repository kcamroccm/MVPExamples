#include "MyPresenter.h"

void UMyPresenter::SetView(UMyWidget* V)
{
    View = V;   // weak reference
}

void UMyPresenter::OnStart()
{
    UE_LOG(LogTemp, Log, TEXT("Presenter: Start button pressed"));
    if (View.IsValid()) View->SetStatus(TEXT("Starting game…
"));
}

void UMyPresenter::OnOptions()
{
    UE_LOG(LogTemp, Log, TEXT("Presenter: Options button pressed"));
    // TODO: open options menu
}

void UMyPresenter::OnQuit()
{
    UE_LOG(LogTemp, Log, TEXT("Presenter: Quit button pressed"));
    // e.g. UGameplayStatics::OpenLevel(this, "MainMenu");
}