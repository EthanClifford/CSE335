/**
 * \file FishMagikarp.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include <string>
#include "FishMagikarp.h"

using namespace Gdiplus;
using namespace std;


/// Fish filename
const wstring FishMagikarpImageName = L"images/magikarp.png";

/// Maximum speed in the X direction in
/// pixels per second
const double MaxSpeedX = 10;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 1;

/// Maximum speed in the Y direction in
/// pixels per second
const double MaxSpeedY = 10;

/// Minimum speed in the Y direction in
/// pixels per second
const double MinSpeedY = 1;

/**
 * Constructor
 *
 * Sets the X and Y speed of the Goldeen to be a random number between a
 * minimum and maximum speed in pixels per second
 * \param aquarium Aquarium this fish is a member of
 */
CFishMagikarp::CFishMagikarp(CAquarium* aquarium) : CFish(aquarium, FishMagikarpImageName)
{
    CFish::SetXSpeed(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
    CFish::SetYSpeed(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return A pointer to the node that we added to the XML file
 */
std::shared_ptr<xmlnode::CXmlNode> CFishMagikarp::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"Magikarp");

    return itemNode;
}

/**
 * Handle updates in time of our Magikarp
 *
 * This is called before we draw and allows us to move our Magikarp.
 *
 * \param elapsed Time elapsed since the last class call
 */
void CFishMagikarp::Update(double elapsed)
{

    CFish::Update(elapsed);

}


