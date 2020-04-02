/**
 * \file HeadTop.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "HeadTop.h"

using namespace Gdiplus;
using namespace std;

/// constant ratio to convert radians to degrees
const double RtoD = 57.295779513;

/** Transform a point from a location on the bitmap to
*  a location on the screen.
* \param  p Point to transform
* \returns Transformed point
*/
Gdiplus::Point CHeadTop::TransformPoint(Gdiplus::Point p)
{
    // Make p relative to the image center
    p = p - GetCenter();

    // Rotate as needed and offset
    return RotatePoint(p, mPlacedR) + mPlacedPosition;
}

/**
 * Constructor
 * \param name Name of the drawable 
 * \param filename File where the drawable is stored
 */
CHeadTop::CHeadTop(const std::wstring& name, const std::wstring& filename) : CImageDrawable(name, filename)
{

}

/**
 * Draws Eyebrow
 * \param graphics The graphics we are drawing in 
 * \param point Point that we start our drawing at
 */
void CHeadTop::DrawEyebrow(Gdiplus::Graphics* graphics, Gdiplus::Point point)
{
    auto state = graphics->Save();
    Pen pen(Color::Black, 2);
    Point p = TransformPoint(Point(55, 85));
    graphics->TranslateTransform(p.X, p.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->DrawLine(&pen, point, Point(point.X + 15, point.Y));
    graphics->Restore(state);
}

/**
 * Draws Eye
 * \param graphics The graphics we are drawing in
 * \param point Point that we start our drawing at
 */
void CHeadTop::DrawEye(Gdiplus::Graphics* graphics, Gdiplus::Point point)
{
    SolidBrush brush(Gdiplus::Color::Black);

    float wid = 15.0f;
    float hit = 20.0f;
    
    auto state = graphics->Save();
    Point p = TransformPoint(Point(55, 85));
    graphics->TranslateTransform(p.X, p.Y);
    graphics->RotateTransform((float)(-mPlacedR * RtoD));
    graphics->FillEllipse(&brush, (-wid / 2) + point.X, (-hit / 2) + point.Y, wid, hit);
    graphics->Restore(state);
}


/**
 * Draws the top of the head
 * \param graphics The graphics we are drawing in
 */
void CHeadTop::Draw(Gdiplus::Graphics* graphics)
{
	CImageDrawable::Draw(graphics);

    DrawEye(graphics, mLeftEyeOffset);
    DrawEye(graphics, mRightEyeOffset);

    DrawEyebrow(graphics, mLeftEyebrowOffset);
    DrawEyebrow(graphics, mRightEyebrowOffset);

}