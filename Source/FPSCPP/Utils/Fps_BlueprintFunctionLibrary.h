// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Fps_BlueprintFunctionLibrary.generated.h"

class AProjectile;

UCLASS()
class FPSCPP_API UFps_BlueprintFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|GameplayUtils")
	static AActor* SpawnActorDeferred(
		const UObject* WorldContextObject,
		TSubclassOf<AProjectile> ProjectileClass,
		const FVector SpawnLocation,
		const FRotator SpawnRotation,
		AActor* SpawnActor);

	UFUNCTION(BlueprintCallable, Category = "AuraAbilitySystemLibrary|GameplayUtils")
	static void FinishSpawn(
		AProjectile* Projectile,
		const FVector& SpawnLocation,
		const FRotator& SpawnRotation,
		const FVector& LaunchDir,
		float GravityScale = 1.f);
};
