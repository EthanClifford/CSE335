/**
 * \file DecorCastle.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include <string>
#include "DecorCastle.h"

using namespace Gdiplus;
using namespace std;


/// Fish filename
const wstring DecorCastleImageName = L"images/castle.png";

/**
 * Constructor
 * \param aquarium Aquarium this castle is a member of
 */
CDecorCastle::CDecorCastle(CAquarium* aquarium) : CItem(aquarium, DecorCastleImageName)
{
}

/**
 * Save this item to an XML node
 * \param node The node we are going to be a child of
 * \return A pointer to the node that we added to the XML file
 */
std::shared_ptr<xmlnode::CXmlNode> CDecorCastle::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
    auto itemNode = CItem::XmlSave(node);

    itemNode->SetAttribute(L"type", L"Castle");

    return itemNode;
}


