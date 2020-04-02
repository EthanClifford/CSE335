/**
 * \file TileGarden.h
 *
 * \author Ethan Clifford
 *
 * Class that implements a Garden Tile
 */

#pragma once
#include "Tile.h"

/**
 * A Garden Tile 
 */
class CTileGarden : public CTile
{
public:
    CTileGarden(CCity* city);

    ///  Default constructor (disabled)
    CTileGarden() = delete;

    ///  Copy constructor (disabled)
    CTileGarden(const CTileGarden&) = delete;

    ~CTileGarden();

    virtual std::shared_ptr<xmlnode::CXmlNode> XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node);

    /** Accept a visitor
    * \param visitor The visitor we accept */
    virtual void Accept(CTileVisitor* visitor) override { visitor->VisitGarden(this); }

    void Prune();

    void Update(double elapsed);

private:
    double mSincePruning = 0;   ///< Time in seconds since the garden tile was last pruned
};

