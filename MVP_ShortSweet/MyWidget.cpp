#include "MyWidget.h"
#include "MyPresenter.h"
#include "Kismet/KismetSystemLibrary.h"

void UMyWidget::NativeConstruct()
{
    Super::NativeConstruct();

    if (Btn_Start)  { Btn_Start->OnClicked.AddDynamic(this, &UMyWidget::OnStartClicked); }
    if (Btn_Options){ Btn_Options->OnClicked.AddDynamic(this, &UMyWidget::OnOptionsClicked); }
    if (Btn_Quit)   { Btn_Quit->OnClicked.AddDynamic(this, &UMyWidget::OnQuitClicked); }
}

void UMyWidget::OnStartClicked()
{
    if (UMyPresenter* P = Presenter.Get()) P->OnStart();
    else                                 UE_LOG(LogTemp, Warning, TEXT("Presenter not set."));
}

void UMyWidget::OnOptionsClicked()
{
    if (UMyPresenter* P = Presenter.Get()) P->OnOptions();
    else                                 UE_LOG(LogTemp, Warning, TEXT("Presenter not set."));
}

void UMyWidget::OnQuitClicked()
{
    if (UMyPresenter* P = Presenter.Get()) P->OnQuit();
    else                                 UE_LOG(LogTemp, Warning, TEXT("Presenter not set."));
}

void UMyWidget::SetStatus(const FString& NewText)
{
    if (UTextBlock* TB = Cast<UTextBlock>(GetWidgetFromName(TEXT("StatusText"))))
        TB->SetText(FText::FromString(NewText));
    else
        UE_LOG(LogTemp, Warning, TEXT("MyWidget: missing StatusText widget."));
}

void UMyWidget::Refresh()
{
    // Empty for demo
}

void UMyWidget::RequestDestroy()
{
    RemoveFromParent();
}