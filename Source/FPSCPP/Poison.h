#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Poison.generated.h"  // Must be last include

// Forward declarations
class APlayerController;
class AFPSCPPCharacter;

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class FPSCPP_API UPoison : public UActorComponent
{
    GENERATED_BODY()

public:
    UPoison();

protected:
    virtual void BeginPlay() override;
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
    class APlayerController* OwningController;
    class AFPSCPPCharacter* Character;

    float TimeSinceLastDamage;
    float DamageInterval;
};