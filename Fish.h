/**
 * \file Fish.h
 *
 * \author Ethan Clifford
 *
 * Base class for a fish
 */

#pragma once
#include "Item.h"


/**
 * Base class for a fish
 * This applies to all of the fish, but not the decor
 * items in the aquarium.
 */
class CFish : public CItem
{
public:
    /// Default constructor (disabled)
    CFish() = delete;

    /// Copy constructor (disabled)
    CFish(const CFish&) = delete;

    virtual void Update(double elapsed);

    virtual std::shared_ptr<xmlnode::CXmlNode>
        XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    virtual void XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node) override;

    /// Sets the speed of the fish in the X direction
    /// \param xSpeed Speed in the X direction
    void SetXSpeed(double xSpeed) { mSpeedX = xSpeed; }

    /// Sets the speed of the fish in the Y direction
    /// \param ySpeed Speed in the Y direction
    void SetYSpeed(double ySpeed) { mSpeedY = ySpeed; }

protected:
    CFish(CAquarium *aquarium, const std::wstring &filename);

private:
    /// Fish speed in the X direction
    double mSpeedX;

    /// Fish speed in the Y direction
    double mSpeedY;
};

