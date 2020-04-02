/**
 * \file Actor.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "Actor.h"
#include "Picture.h"

using namespace Gdiplus;
/**
 * Constructor
 * \param name The name of the actor
 */
CActor::CActor(const std::wstring& name)
{
    mName = name;
}

/// Destructor
CActor::~CActor()
{

}

/**
 * Sets the root
 * \param root Pointer to the root to be used
 */
void CActor::SetRoot(std::shared_ptr<CDrawable> root)
{
    mRoot = root;
}

/**
 * Draws the actor
 * \param graphics The graphics to draw in 
 */
void CActor::Draw(Gdiplus::Graphics* graphics)
{
    // Don't draw if not enabled
    if (!mEnabled)
    {
        return;
    }

    // This takes care of determining the absolute placement
    // of all of the child drawables.  We have to determine this
    // in tree order, which may not be the order we draw.
    if (mRoot != nullptr)
    {
        mRoot->Place(mPosition, 0);
    }

    for (auto drawable : mDrawablesInOrder)
    {
        drawable->Draw(graphics);
    }
}

/**
 * Tests if there have been any collisions
 * \param pos The position of the other actor
 * \returns A drawable pointer
 */
std::shared_ptr<CDrawable> CActor::HitTest(Gdiplus::Point pos)
{
    // If not enabled or not clickable, we indicate no hit.
    if (!mClickable || !mEnabled)
    {
        return nullptr;
    }

    // Since this list is in drawing order, we really want to know the last thing drawn
    // under the mouse, since it will be on top.  So, we reverse iterate over the list.
    for (auto d = mDrawablesInOrder.rbegin(); d != mDrawablesInOrder.rend(); d++)
    {
        auto drawable = *d;
        if (drawable->HitTest(pos))
        {
            return drawable;
        }
    }

    return nullptr;
}

/**
 * Adds a drawable to the Actor
 * \param drawable The Drawable to be added
 */
void CActor::AddDrawable(std::shared_ptr<CDrawable> drawable)
{
    mDrawablesInOrder.push_back(drawable);
    drawable->SetActor(this);
}

/** Set the picture link for this actor.
* 
* This is telling the actor what picture to use.
*
* Also tells all child drawables what the timeline is.
* \param pic The picture we are using
*/
void CActor::SetPicture(CPicture* pic)
{
    mPicture = pic;

    // Set the timeline for all drawables.  This links the channels to
    // the timeline system.
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->SetTimeline(mPicture->GetTimeline());
    }
}

/** Add the channels for this actor to a timeline
 * \param timeline The timeline class.
 */
void CActor::SetTimeline(CTimeline* timeline)
{
    timeline->AddChannel(&mChannel);
}

/** Sets the keyframe of the drawables and the actor 
*/
void CActor::SetKeyframe()
{
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->SetKeyframe();
    }

    mChannel.SetKeyframe(mPosition);
}

/** Gets the keyframe of the drawables and the actor
*/
void CActor::GetKeyframe()
{
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->GetKeyframe();
    }

    if (mChannel.IsValid())
    {
        mPosition = mChannel.GetPosition();
    }
}

/** Removes the keyframe of the drawables and the actor
*/
void CActor::RemoveKeyframe()
{
    for (auto drawable : mDrawablesInOrder)
    {
        drawable->RemoveKeyframe();
    }

    mChannel.RemoveKeyframe();
}