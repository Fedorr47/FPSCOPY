#include "Poison.h"
#include "FPSCPPCharacter.h"
#include "Engine/Engine.h"
#include "GameFramework/PlayerController.h"

UPoison::UPoison()
{
    PrimaryComponentTick.bCanEverTick = true;

    OwningController = nullptr;
    Character = nullptr;
    TimeSinceLastDamage = 0.0f;
    DamageInterval = 1.0f;
}

void UPoison::BeginPlay()
{
    Super::BeginPlay();

    OwningController = Cast<APlayerController>(GetOwner());
    if (OwningController)
    {
        Character = Cast<AFPSCPPCharacter>(OwningController->GetPawn());
    }
}

void UPoison::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (Character)
    {
        TimeSinceLastDamage += DeltaTime;

        if (TimeSinceLastDamage >= DamageInterval)
        {
            // Use the UpdateHealth function instead of directly modifying hp
            Character->UpdateHealth(-1.0f);

            // Debug message
            /*if (GEngine)
            {
                FString DamageMessage = FString::Printf(TEXT("Poison damage! HP: %.1f"), Character->hp);
                GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, DamageMessage);
            }

            UE_LOG(LogTemp, Warning, TEXT("Poison damage applied. Current HP: %.1f"), Character->hp);*/

            // Reset timer
            TimeSinceLastDamage = 0.0f;
        }
    }
}