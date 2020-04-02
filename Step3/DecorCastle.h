/**
 * \file FishBeta.h
 *
 * \author Ethan Clifford
 *
 * Class that initializes a Castle decoration.
 */

#pragma once
#include <memory>
#include "Item.h"

 /**
  * Implements a Castle decoration
  */
class CDecorCastle : public CItem
{
public:
    /// Default constructor (disabled)
    CDecorCastle() = delete;

    /// Copy constructor (disabled)
    CDecorCastle(const CDecorCastle&) = delete;

    CDecorCastle(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;
};

