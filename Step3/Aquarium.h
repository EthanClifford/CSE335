/**
 * \file Aquarium.h
 *
 * \author Ethan Clifford
 *
 * Class that implements an Aquarium
 */


#pragma once
#include <memory>
#include <string>
#include <vector>
#include "XmlNode.h"

class CItem;


/**
 * The class that manages our aquarium
 */
class CAquarium
{
public:
    CAquarium();

    void OnDraw(Gdiplus::Graphics* graphics);

    void Add(std::shared_ptr<CItem> item);

    std::shared_ptr<CItem> HitTest(int x, int y);

    void MoveItemToEnd(std::shared_ptr<CItem> item);
    
    bool ItemDistance(CItem* item, double minDistance);

    void Save(const std::wstring& filename);

    void Load(const std::wstring& filename);

    void Clear();

    void XmlItem(const std::shared_ptr<xmlnode::CXmlNode> &node);

    void Update(double elapsed);

    /// Get the width of the aquarium
    /// \returns Aquarium width
    int GetWidth() const { return mBackground->GetWidth(); }

    /// Get the height of the aquarium
    /// \returns Aquarium height
    int GetHeight() const { return mBackground->GetHeight(); }

private:
    std::unique_ptr<Gdiplus::Bitmap> mBackground; ///< Background image to use

    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<CItem> > mItems;
};

