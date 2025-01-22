#include "FillShapeState.h"
#include "ToolBar.h"
#include "FillOutlineState.h"
#include "DragAndDropState.h"

void FillShapeState::DragAndDrop(Toolbar* toolbar) const
{
	toolbar->SetState(new DragAndDropState());
}

void FillShapeState::FillShape(Toolbar* toolbar) const
{
}

void FillShapeState::FillOutline(Toolbar* toolbar) const
{
	toolbar->SetState(new FillOutlineState());
}
