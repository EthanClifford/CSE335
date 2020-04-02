/**
 * \file AnimChannelPoint.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "AnimChannelPoint.h"

using namespace Gdiplus;
using namespace std;

CAnimChannelPoint::CAnimChannelPoint() : CAnimChannel()
{

}

CAnimChannelPoint::~CAnimChannelPoint()
{

}

/**
* Set a keyframe
*
* This function allocates a new keyframe and sends it to
* CAnimChannel, which will insert it into the collection of keyframes.
*
* \param p Point for the keyframe.
*/
void CAnimChannelPoint::SetKeyframe(Point p)
{
    //  Create a keyframe of the appropriate type
    // Telling it this channel and the Point
    shared_ptr<KeyframePoint> keyframe = make_shared<KeyframePoint>(this, p);

    // Insert it into the collection
    InsertKeyframe(keyframe);
}

/**
 * Compute an Point that is an interpolation between two keyframes
 *
 * This function is called after Use1 and Use2, so we have pointers to
 * to valid keyframes of the type KeyframePoint. This function does the
 * tweening.
 * \param t A t value. t=0 means keyframe1, t=1 means keyframe2. Other values
 * interpolate between.
 */
void CAnimChannelPoint::Tween(double t)
{
    Point point1 = mKeyframe1->GetPoint();
    Point point2 = mKeyframe2->GetPoint();
    mPoint = Point(int(point1.X + t * (point2.X - point1.X)), int(point1.Y + t * (point2.Y - point1.Y)));
}