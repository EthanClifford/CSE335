/**
 * \file FishMagikarp.h
 *
 * \author Ethan Clifford
 *
 * Class that initializes a Magikarp.
 */

#pragma once
#include <memory>
#include "Fish.h"

/**
 * Implements a Magikarp
 */
class CFishMagikarp : public CFish
{
public:
    /// Default constructor (disabled)
    CFishMagikarp() = delete;

    /// Copy constructor (disabled)
    CFishMagikarp(const CFishMagikarp&) = delete;

    CFishMagikarp(CAquarium* aquarium);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void Update(double elapsed) override;
};

