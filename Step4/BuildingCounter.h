/**
 * \file BuildingCounter.h
 *
 * \author Ethan Clifford
 *
 * Counts how many buildings there are in the city
 */

#pragma once
#include "TileVisitor.h"


/**
 * Class that counts how many buildings there are in a city.
 */
class CBuildingCounter : public CTileVisitor
{
public:
    /** Get the number of buildings
    * \returns Number of buildings */
    int GetNumBuildings() const { return mNumBuildings; }

    void VisitBuilding(CTileBuilding* building);

private:
    /// Buildings counter
    int mNumBuildings = 0;
};

