#include "TLPlayerController.h"

ATLPlayerController::ATLPlayerController()
{
	SelectedHex = nullptr;
	SelectedUnit = nullptr;
	CurrentAction = EPlayerAction::PlaceUnit;
}

void ATLPlayerController::SelectHex(AHexTile* Hex)
{
	SelectedHex = Hex;
	OnHexClicked.Broadcast(Hex);
}

void ATLPlayerController::SelectUnit(AUnit* Unit)
{
	SelectedUnit = Unit;
	OnUnitSelected.Broadcast(Unit);
}

void ATLPlayerController::ConfirmAction(EPlayerAction Action)
{
	CurrentAction = Action;
	OnActionConfirmed.Broadcast(Action);
}

void ATLPlayerController::EndTurn()
{
	OnTurnEnd.Broadcast();
	ClearSelection();
}

void ATLPlayerController::ClearSelection()
{
	SelectedHex = nullptr;
	SelectedUnit = nullptr;
}
