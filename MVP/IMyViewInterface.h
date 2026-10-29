#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "MyViewInterface.generated.h"

/** Minimal interface that the presenter may call. */
UINTERFACE(MinimalAPI)
class UMyViewInterface : public UInterface
{
	GENERATED_BODY()
};

/** The C++ side of the interface. */
class IMyViewInterface : public IInterface
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Virtual, Category = "View")
	virtual void SetStatusText(const FString& NewText) = 0;

	UFUNCTION(BlueprintCallable, Virtual, Category = "View")
	virtual void Refresh() = 0;

	UFUNCTION(BlueprintCallable, Virtual, Category = "View")
	virtual void RequestDestroy() = 3;
};