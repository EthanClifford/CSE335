/**
 * \file PolyDrawable.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "PolyDrawable.h"

using namespace Gdiplus;
using namespace std;

/**
 * Constructor
 * \param name The name of the drawable 
 */
CPolyDrawable::CPolyDrawable(std::wstring name) : CDrawable(name)
{

}

/**
 * Draws the drawable
 * \param graphics The graphics we are drawing in
 */
void CPolyDrawable::Draw(Gdiplus::Graphics* graphics)
{
    SolidBrush brush(mColor);

    // Transform the points
    vector<Point> points;
    for (auto point : mPoints)
    {
        points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
    }

    graphics->FillPolygon(&brush, &points[0], (int)mPoints.size());
}

/**
 * Checks if a collision happened at a location
 * \param pos The location we are checking for a collision at
 * \returns true if there is a collision, false otherwise
 */
bool CPolyDrawable::HitTest(Gdiplus::Point pos)
{
    //Transform the points
    vector<Point> points;
    for (auto point : mPoints)
    {
        points.push_back(RotatePoint(point, mPlacedR) + mPlacedPosition);
    }

    GraphicsPath path;
    path.AddPolygon(&points[0], (int)points.size());
    return path.IsVisible(pos) ? true : false;
}

/**
 * Adds a point to the list of points
 * \param point The point to be added
 */
void CPolyDrawable::AddPoint(Gdiplus::Point point)
{
    mPoints.push_back(point);
}
