/**
 * \file BuildingCounter.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "BuildingCounter.h"

/** Visit a CTileBuilding object
* \param building Building we are visiting */
void CBuildingCounter::VisitBuilding(CTileBuilding* building)
{
    mNumBuildings++;
}