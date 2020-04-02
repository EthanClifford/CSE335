/**
 * \file TileGarden.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "TileGarden.h"

using namespace std;
using namespace Gdiplus;


/// Initial image of the garden
const wstring GardenImage = L"garden.png";

/// Image for the first stage of overgrowth
const wstring Overgrown1Image = L"garden1.png";

/// Time to reach the first overgrown stage in milliseconds
const double Overgrown1 = 2;

/// Image for the second stage of overgrowth
const wstring Overgrown2Image = L"garden2.png";

/// Time to reach the second overgrown stage in milliseconds
const double Overgrown2 = 4;

/// Image for the third stage of overgrowth
const wstring Overgrown3Image = L"garden3.png";

/// Time to reach the third overgrown stage in milliseconds
const double Overgrown3 = 7;

/// Image for the final stage of overgrowth
const wstring Overgrown4Image = L"garden4.png";

/// Time to reach the final overgrown stage in milliseconds
const double Overgrown4 = 10;


 /** Constructor
 * \param city The city this is a member of
 */
CTileGarden::CTileGarden(CCity* city) : CTile(city)
{
    SetImage(GardenImage);
}

/**
*  Destructor
*/
CTileGarden::~CTileGarden()
{
}

/**  Save this item to an XML node
* \param node The node we are going to be a child of
* \returns Allocated node
*/
std::shared_ptr<xmlnode::CXmlNode> CTileGarden::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CTile::XmlSave(node);

    itemNode->SetAttribute(L"type", L"Garden");
    itemNode->SetAttribute(L"file", GetFile());

    return itemNode;
}


/**
* brief Load the attributes for an item node.
* \param node The Xml node we are loading the item from
*/
void CTileGarden::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    CTile::XmlLoad(node);
    SetImage(node->GetAttributeValue(L"file", L""));
}

/** 
* Prunes the garden by setting the image to the initial image of a garden
* and resetting mSincePruning to 0.
*/
void CTileGarden::Prune()
{
    SetImage(GardenImage);
    mSincePruning = 0;
}

/** Updates the image to refelct any changes in the garden tile's state
*
* In this case that means changing the image based on the amount of time since the
* garden was last pruned
* 
* \param elapsed Time elapsed since Update was last called, in seconds
*/
void CTileGarden::Update(double elapsed)
{
    CTile::Update(elapsed);

    mSincePruning += elapsed;

    if (mSincePruning >= Overgrown4)
    {
        SetImage(Overgrown4Image);
    }
    else if (mSincePruning >= Overgrown3)
    {
        SetImage(Overgrown3Image);
    }
    else if (mSincePruning >= Overgrown2)
    {
        SetImage(Overgrown2Image);
    }
    else if (mSincePruning >= Overgrown1)
    {
        SetImage(Overgrown1Image);
    }
}
