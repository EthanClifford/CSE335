/**
 * \file PolyDrawable.h
 *
 * \author Ethan Clifford
 *
 * A drawable based on polygon images
 */

#pragma once
#include <vector>
#include "Drawable.h"


/**
* A drawable based on polygon images.
*
* This class has a list of points and draws a polygon
* drawable based on those points.
*/
class CPolyDrawable : public CDrawable
{
public:

    /** \brief Default constructor disabled */
    CPolyDrawable() = delete;
    /** \brief Copy constructor disabled */
    CPolyDrawable(const CPolyDrawable &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CPolyDrawable &) = delete;

    CPolyDrawable(std::wstring name);

    void Draw(Gdiplus::Graphics* graphics) override;

    bool HitTest(Gdiplus::Point pos);

    void AddPoint(Gdiplus::Point point);

    /** The polygon's color
    * \returns color */
    Gdiplus::Color GetColor() const { return mColor; }

    /** Set the polygon's color
    * \param c New color */
    void SetColor(Gdiplus::Color c) { mColor = c; }
private:
    /// The polygon color
    Gdiplus::Color mColor = Gdiplus::Color::Black;

    /// The points that are being drawn at
    std::vector<Gdiplus::Point> mPoints;
};

