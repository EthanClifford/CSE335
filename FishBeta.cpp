/**
 * \file FishBeta.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include <string>
#include "FishBeta.h"

using namespace Gdiplus;
using namespace std;


/// Fish filename
const wstring FishBetaImageName = L"images/beta.png";

/// Maximum speed in the X direction in
/// pixels per second
const double MaxSpeedX = 100;

/// Minimum speed in the X direction in
/// pixels per second
const double MinSpeedX = 50;

/// Maximum speed in the Y direction in
/// pixels per second
const double MaxSpeedY = 100;

/// Minimum speed in the Y direction in
/// pixels per second
const double MinSpeedY = 50;

/**
 * Constructor
 *
 * Sets the X and Y speed of the Goldeen to be a random number between a
 * minimum and maximum speed in pixels per second
 * \param aquarium Aquarium this fish is a member of 
 */
CFishBeta::CFishBeta(CAquarium* aquarium) : CFish(aquarium, FishBetaImageName)
{
    CFish::SetXSpeed(MinSpeedX + ((double)rand() / RAND_MAX) * (MaxSpeedX - MinSpeedX));
    CFish::SetYSpeed(MinSpeedY + ((double)rand() / RAND_MAX) * (MaxSpeedY - MinSpeedY));
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of 
 * \return A pointer to the node that we added to the XML file
 */
std::shared_ptr<xmlnode::CXmlNode> CFishBeta::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CFish::XmlSave(node);

    itemNode->SetAttribute(L"type", L"beta");

    return itemNode;
}

/**
 * Handle updates in time of our Beta fish
 *
 * This is called before we draw and allows us to move our Beta fish.
 * 
 * \param elapsed Time elapsed since the last class call
 */
void CFishBeta::Update(double elapsed)
{

    CFish::Update(elapsed);

}

