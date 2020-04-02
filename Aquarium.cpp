/**
 * \file Aquarium.cpp
 *
 * \author Ethan Clifford
 */

#include <algorithm>
#include "pch.h"
#include "Aquarium.h"
#include "Fishbeta.h"
#include "XmlNode.h"
#include "FishGoldeen.h"
#include "FishMagikarp.h"
#include "DecorCastle.h"

using namespace Gdiplus;
using namespace std;
using namespace xmlnode;


/**
 * Constructor
 */
CAquarium::CAquarium()
{
    mBackground = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/background1.png"));
    if (mBackground->GetLastStatus() != Ok)
    {
        AfxMessageBox(L"Failed to open images/background1.png");
    }
}

/**
 * Draw the aquarium
 * \param graphics The GDI+ graphics context to draw on
 */
void CAquarium::OnDraw(Gdiplus::Graphics* graphics)
{
    graphics->DrawImage(mBackground.get(), 0, 0, mBackground->GetWidth(), mBackground->GetHeight());

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily, 16);

	SolidBrush green(Color(0, 64, 0));
	graphics->DrawString(L"Under the sea!", -1, &font, PointF(2, 2), &green);

    for (auto item : mItems)
    {
        item->Draw(graphics);
    }
}

/**
 * Add an item to the aquarium
 * \param item New item to add
 */
void CAquarium::Add(std::shared_ptr<CItem> item)
{
    mItems.push_back(item);
}

/** Test an x,y click location to see if it clicked
 * on some item in the aquarium
 * \param x X location
 * \param y Y location
 * \returns Pointer to item we clicked on or nullptr if none
 */
std::shared_ptr<CItem> CAquarium::HitTest(int x, int y)
{
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i)->HitTest(x, y))
        {
            return *i;
        }
    }
    return nullptr;
}

/**
 * Moves an item to the end of the list of items
 * \param item 
 */
void CAquarium::MoveItemToEnd(shared_ptr<CItem> item)
{
    auto loc = find(begin(mItems), end(mItems), item);
    if (loc != end(mItems))
    {
        auto locValue = *loc;
        mItems.erase(loc);
        mItems.push_back(locValue);
    }
}

/**
 * Determines if there is an object within a certain distance of the provided item
 * \param item The item that the distances will be measured from
 * \param minDistance The minimum distance away from the provided object that any item can be.
 * \returns True if there is another item inside of minDistance of the provided item.  False otherwise.
 */
bool CAquarium::ItemDistance(CItem* item, double minDistance)
{
    double distance = 0;
    for (auto i = mItems.rbegin(); i != mItems.rend(); i++)
    {
        if ((*i).get() != item)
        {
            // Determine how far away the two items are
            double dx = (*i)->GetX() - item->GetX();
            double dy = (*i)->GetY() - item->GetY();
            distance = sqrt(dx * dx + dy * dy);

            if (distance < minDistance)
            {
                return true;
            }
        }
    }
    return false;
}

/**
 * Save the aquarium as a .aqua XML file.
 *
 * Open an XML file and stream the aquarium data to it.
 *
 * \param filename The filename of the file to save the aquarium to 
 */
void CAquarium::Save(const std::wstring &filename)
{
    //
    // Create an XML document
    //
    auto root = CXmlNode::CreateDocument(L"aqua");

    // Iterate over all items and save them
    for (auto item : mItems)
    {
        item->XmlSave(root);
    }

    try
    {
        root->Save(filename);
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Load the aquarium from a .aqua XML file
 *
 * Opens the XML file and reads the nodes, creating items as appropriate
 *
 * \param filename The filename of the file to load the aquarium from.
 */
void CAquarium::Load(const std::wstring& filename)
{
    // We surround with a try/catch to handle errors
    try
    {
        // Open the document to read
        shared_ptr<CXmlNode> root = CXmlNode::OpenDocument(filename);

        // Once we know it is open, clear the existing data
        Clear();

        //
        // Traverse the children of the root
        // node of the XML document in memory!!!!
        //
        for (auto node : root->GetChildren())
        {
            if (node->GetType() == NODE_ELEMENT && node->GetName() == L"item")
            {
                XmlItem(node);
            }
        }
    }
    catch (CXmlNode::Exception ex)
    {
        AfxMessageBox(ex.Message().c_str());
    }
}

/**
 * Clear the data out of the current aquarium
 */
void CAquarium::Clear()
{
    mItems.clear();
}

/**
 * Handle an item ndoe.
 * \param node Pointer to the XML node we are handling
 */
void CAquarium::XmlItem(const std::shared_ptr<xmlnode::CXmlNode> &node)
{
    // A pointer for the item we are loading
    shared_ptr<CItem> item;

    // We have an item.  What type?
    wstring type = node->GetAttributeValue(L"type", L"");
    if (type == L"beta")
    {
        item = make_shared<CFishBeta>(this);
    }
    else if (type == L"Goldeen")
    {
        item = make_shared<CFishGoldeen>(this);
    }
    else if (type == L"Magikarp")
    {
        item = make_shared<CFishMagikarp>(this);
    }
    else if (type == L"Castle")
    {
        item = make_shared<CDecorCastle>(this);
    }

    if (item != nullptr)
    {
        item->XmlLoad(node);
        Add(item);
    }
}

/**
 * Handle updates for animation
 * \param elapsed The time since the last update
 */
void CAquarium::Update(double elapsed)
{
    for (auto item : mItems)
    {
        item->Update(elapsed);
    }
}