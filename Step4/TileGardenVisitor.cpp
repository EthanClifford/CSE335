/**
 * \file TileGardenVisitor.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "TileGardenVisitor.h"
#include "TileGarden.h"


/** Visit a CTileGarden object
* \param garden Garden tile that we are visiting */
void CTileGardenVisitor::VisitGarden(CTileGarden* garden)
{
    garden->Prune();
}
