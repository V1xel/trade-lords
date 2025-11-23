#pragma once

#include "CoreMinimal.h"
#include "GameFlowTypes.generated.h"

UENUM(BlueprintType)
enum class EGamePhase : uint8
{
	Setup UMETA(DisplayName = "Setup"),
	LordSelection UMETA(DisplayName = "Lord Selection"),
	Action UMETA(DisplayName = "Action"),
	Production UMETA(DisplayName = "Production"),
	EndRound UMETA(DisplayName = "End Round"),
	GameEnd UMETA(DisplayName = "Game End")
};

UENUM(BlueprintType)
enum class EPlayerAction : uint8
{
	PlaceUnit UMETA(DisplayName = "Place Unit"),
	BuyResource UMETA(DisplayName = "Buy Resource"),
	SellResource UMETA(DisplayName = "Sell Resource"),
	TakeContract UMETA(DisplayName = "Take Contract"),
	FulfillContract UMETA(DisplayName = "Fulfill Contract"),
	UpgradeShipping UMETA(DisplayName = "Upgrade Shipping"),
	EndTurn UMETA(DisplayName = "End Turn")
};
