/**
 * \file Drawable.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include <cmath>
#include "Drawable.h"
#include "Actor.h"
#include "Timeline.h"

/**
* Constructor
* \param name The drawable name
*/
CDrawable::CDrawable(const std::wstring& name)
{
    mName = name;
}

/// Destructor
CDrawable::~CDrawable()
{

}

/**
* Rotate a point by some angle
* \param point Point to rotate
* \param angle Angle in radians
* \returns Rotated point
*/
Gdiplus::Point CDrawable::RotatePoint(Gdiplus::Point point, double angle)
{
    double cosA = cos(angle);
    double sinA = sin(angle);

    return Gdiplus::Point(int(cosA * point.X + sinA * point.Y), int(-sinA * point.X + cosA * point.Y));
}

/**
* Set the actor using this drawable
* \param actor Actor using this drawable
*/
void CDrawable::SetActor(CActor* actor)
{
    mActor = actor;

    // Set the channel name
    mChannel.SetName(actor->GetName() + L":" + mName);
}

/**
* Place this drawable relative to its parent
* \param offset Parent offset
* \param rotate Parent rotation
*/
void CDrawable::Place(Gdiplus::Point offset, double rotate)
{
    // Combine the transformation we are given with the transformation for this object
    mPlacedPosition = offset + RotatePoint(mPosition, rotate);
    mPlacedR = mRotation + rotate;

    // Update our children
    for (auto drawable : mChildren)
    {
        drawable->Place(mPlacedPosition, mPlacedR);
        
    }
}

/**
* Add a child drawable to this drawable
* \param child The child to add
*/
void CDrawable::AddChild(std::shared_ptr<CDrawable> child)
{
    mChildren.push_back(child);
    child->SetParent(this);
}

/**
* Move this drawable some amount
* \param delta The amount to move
*/
void CDrawable::Move(Gdiplus::Point delta)
{
    if (mParent != nullptr)
    {
        mPosition = mPosition + RotatePoint(delta, -mParent->mPlacedR);
    }
    else
    {
        mPosition = mPosition + delta;;
    }
}

/** Add the channels for this drawable to a timeline
 * \param timeline The timeline class.
 */
void CDrawable::SetTimeline(CTimeline* timeline)
{
    timeline->AddChannel(&mChannel);
}

/** Sets the keyframe for this drawable */
void CDrawable::SetKeyframe()
{
    mChannel.SetKeyframe(mRotation);
}

/** Gets the keyframe for this drawable if the channel is valid */
void CDrawable::GetKeyframe()
{
    if (mChannel.IsValid())
    {
        mRotation = mChannel.GetAngle();
    }
}

/** Removes the keyframe for this drawable */
void CDrawable::RemoveKeyframe()
{
    mChannel.RemoveKeyframe();
}