/**
 * \file FishBeta.h
 *
 * \author Ethan Clifford
 *
 * Class that initializes a Beta fish.
 */

#pragma once
#include <memory>
#include "Fish.h"

/**
 * Implements a Beta Fish
 */
class CFishBeta : public CFish
{
public:
    /// Default constructor (disabled)
    CFishBeta() = delete;

    /// Copy constructor (disabled)
    CFishBeta(const CFishBeta &) = delete;

    CFishBeta(CAquarium *aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode> 
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;
};
