/**
 * \file TileGardenVisitor.h
 *
 * \author Ethan Clifford
 *
 * Visitor for garden tiles
 */

#pragma once
#include "TileVisitor.h"


/**
 * Class that implements the garden tile visitor
 */
class CTileGardenVisitor : public CTileVisitor
{
public:
	virtual void VisitGarden(CTileGarden* garden) override;
};

