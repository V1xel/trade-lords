// Copyright Epic Games, Inc. All Rights Reserved.

#include "BlueprintGraphHelper.h"
#include "Engine/Blueprint.h"
#include "EdGraph/EdGraph.h"
#include "EdGraph/EdGraphNode.h"
#include "EdGraph/EdGraphPin.h"
#include "K2Node_Event.h"
#include "K2Node_CallFunction.h"
#include "Kismet2/BlueprintEditorUtils.h"
#include "Kismet2/KismetEditorUtilities.h"
#include "KismetCompiler.h"

bool UBlueprintGraphHelper::AddPrintStringToBeginPlay(UBlueprint* Blueprint, const FString& PrintText)
{
	if (!Blueprint)
	{
		UE_LOG(LogTemp, Error, TEXT("Blueprint is null"));
		return false;
	}

	// Find the event graph
	UEdGraph* EventGraph = nullptr;
	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (Graph->GetName().Contains(TEXT("EventGraph")))
		{
			EventGraph = Graph;
			break;
		}
	}

	if (!EventGraph)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find EventGraph"));
		return false;
	}

	// Find or create BeginPlay event node
	UK2Node_Event* BeginPlayNode = nullptr;
	for (UEdGraphNode* Node : EventGraph->Nodes)
	{
		UK2Node_Event* EventNode = Cast<UK2Node_Event>(Node);
		if (EventNode && EventNode->EventReference.GetMemberName() == FName(TEXT("ReceiveBeginPlay")))
		{
			BeginPlayNode = EventNode;
			break;
		}
	}

	// If BeginPlay node doesn't exist, create it
	if (!BeginPlayNode)
	{
		BeginPlayNode = NewObject<UK2Node_Event>(EventGraph);
		BeginPlayNode->EventReference.SetExternalMember(FName(TEXT("ReceiveBeginPlay")), AActor::StaticClass());
		BeginPlayNode->bOverrideFunction = true;

		EventGraph->AddNode(BeginPlayNode, false, false);
		BeginPlayNode->CreateNewGuid();
		BeginPlayNode->PostPlacedNewNode();
		BeginPlayNode->AllocateDefaultPins();
		BeginPlayNode->NodePosX = 0;
		BeginPlayNode->NodePosY = 0;
	}

	// Create Print String node
	UK2Node_CallFunction* PrintNode = NewObject<UK2Node_CallFunction>(EventGraph);

	// Set the function to call (PrintString from KismetSystemLibrary)
	UFunction* PrintStringFunc = FindObject<UFunction>(nullptr, TEXT("/Script/Engine.KismetSystemLibrary:PrintString"));
	if (!PrintStringFunc)
	{
		UE_LOG(LogTemp, Error, TEXT("Could not find PrintString function"));
		return false;
	}

	PrintNode->SetFromFunction(PrintStringFunc);

	// Add to graph
	EventGraph->AddNode(PrintNode, false, false);
	PrintNode->CreateNewGuid();
	PrintNode->PostPlacedNewNode();
	PrintNode->AllocateDefaultPins();

	// Position the node
	PrintNode->NodePosX = BeginPlayNode->NodePosX + 300;
	PrintNode->NodePosY = BeginPlayNode->NodePosY;

	// Connect execution pins
	UEdGraphPin* BeginPlayExecPin = nullptr;
	for (UEdGraphPin* Pin : BeginPlayNode->Pins)
	{
		if (Pin->Direction == EGPD_Output && Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			BeginPlayExecPin = Pin;
			break;
		}
	}

	UEdGraphPin* PrintExecPin = nullptr;
	UEdGraphPin* PrintStringPin = nullptr;
	for (UEdGraphPin* Pin : PrintNode->Pins)
	{
		if (Pin->Direction == EGPD_Input && Pin->PinType.PinCategory == UEdGraphSchema_K2::PC_Exec)
		{
			PrintExecPin = Pin;
		}
		else if (Pin->PinName == FName(TEXT("InString")))
		{
			PrintStringPin = Pin;
		}
	}

	// Connect the pins
	if (BeginPlayExecPin && PrintExecPin)
	{
		BeginPlayExecPin->MakeLinkTo(PrintExecPin);
	}

	// Set the print text
	if (PrintStringPin)
	{
		PrintStringPin->DefaultValue = PrintText;
	}

	// Mark blueprint as modified
	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

	UE_LOG(LogTemp, Log, TEXT("Successfully added Print String node with text: %s"), *PrintText);
	return true;
}

bool UBlueprintGraphHelper::AddCustomEvent(UBlueprint* Blueprint, const FString& EventName)
{
	if (!Blueprint)
	{
		return false;
	}

	// Find event graph
	UEdGraph* EventGraph = nullptr;
	for (UEdGraph* Graph : Blueprint->UbergraphPages)
	{
		if (Graph->GetName().Contains(TEXT("EventGraph")))
		{
			EventGraph = Graph;
			break;
		}
	}

	if (!EventGraph)
	{
		return false;
	}

	// Create custom event node
	UK2Node_Event* CustomEventNode = NewObject<UK2Node_Event>(EventGraph);
	CustomEventNode->CustomFunctionName = FName(*EventName);
	CustomEventNode->bOverrideFunction = false;

	EventGraph->AddNode(CustomEventNode, false, false);
	CustomEventNode->CreateNewGuid();
	CustomEventNode->PostPlacedNewNode();
	CustomEventNode->AllocateDefaultPins();
	CustomEventNode->NodePosX = 0;
	CustomEventNode->NodePosY = 200;

	FBlueprintEditorUtils::MarkBlueprintAsStructurallyModified(Blueprint);

	return true;
}

bool UBlueprintGraphHelper::ConnectNodes(UBlueprint* Blueprint, const FString& SourceNodeName, const FString& SourcePinName, const FString& TargetNodeName, const FString& TargetPinName)
{
	// Implementation for connecting arbitrary nodes
	// This would require finding nodes by name and connecting specified pins
	return false;
}

bool UBlueprintGraphHelper::CompileBlueprint(UBlueprint* Blueprint)
{
	if (!Blueprint)
	{
		return false;
	}

	FKismetEditorUtilities::CompileBlueprint(Blueprint);
	return true;
}
