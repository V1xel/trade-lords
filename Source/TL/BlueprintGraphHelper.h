// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BlueprintGraphHelper.generated.h"

/**
 * Blueprint Function Library for programmatic Blueprint graph editing
 * Exposes K2Node graph manipulation to Python scripts
 */
UCLASS()
class TL_API UBlueprintGraphHelper : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	/**
	 * Add a Print String node connected to BeginPlay event in a Blueprint
	 *
	 * @param Blueprint The Blueprint to modify
	 * @param PrintText The text to print
	 * @return True if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Graph Editing")
	static bool AddPrintStringToBeginPlay(UBlueprint* Blueprint, const FString& PrintText);

	/**
	 * Add a custom event node to a Blueprint
	 *
	 * @param Blueprint The Blueprint to modify
	 * @param EventName Name of the custom event
	 * @return True if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Graph Editing")
	static bool AddCustomEvent(UBlueprint* Blueprint, const FString& EventName);

	/**
	 * Connect two nodes in a Blueprint graph
	 *
	 * @param Blueprint The Blueprint to modify
	 * @param SourceNodeName Name of source node
	 * @param SourcePinName Name of source pin
	 * @param TargetNodeName Name of target node
	 * @param TargetPinName Name of target pin
	 * @return True if successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Graph Editing")
	static bool ConnectNodes(UBlueprint* Blueprint, const FString& SourceNodeName, const FString& SourcePinName, const FString& TargetNodeName, const FString& TargetPinName);

	/**
	 * Compile a Blueprint after modifications
	 *
	 * @param Blueprint The Blueprint to compile
	 * @return True if compilation successful
	 */
	UFUNCTION(BlueprintCallable, Category = "Blueprint Graph Editing")
	static bool CompileBlueprint(UBlueprint* Blueprint);
};
