/**
 * \file FishGoldeen.h
 *
 * \author Ethan Clifford
 *
 * Class that initializes a Goldeen.
 */

#pragma once
#include <memory>
#include "Fish.h"

 /**
  * Implements a Goldeen
  */
class CFishGoldeen : public CFish
{
public:
    /// Default constructor (disabled)
    CFishGoldeen() = delete;

    /// Copy constructor (disabled)
    CFishGoldeen(const CFishGoldeen&) = delete;

    CFishGoldeen(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;
};

