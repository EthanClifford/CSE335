/**
 * \file Actor.h
 *
 * \author Ethan Clifford
 *
 * Class for actors in our drawings.
 */

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "Drawable.h"
#include "AnimChannelPoint.h"

class CPicture;

 /**
  * Class for actors in our drawings.
  *
  * An actor is some graphical object that consists of
  * one or more parts. Actors can be animated.
  */
class CActor
{
public:
    CActor(const std::wstring& name);

    virtual ~CActor();

    /** Default constructor disabled */
    CActor() = delete;
    /** Copy constructor disabled */
    CActor(const CActor&) = delete;
    /** Assignment operator diabled */
    void operator=(const CActor&) = delete;

    void SetRoot(std::shared_ptr<CDrawable> root);

    void Draw(Gdiplus::Graphics *graphics);

    std::shared_ptr<CDrawable> HitTest(Gdiplus::Point pos);

    void AddDrawable(std::shared_ptr<CDrawable> drawable);

    /**
    * Gets the name of the actor
    * \return The string that contains the actor's name
    */
    std::wstring GetName() const { return mName; }

    /** Actor is enabled
    * \returns enabled status */
    bool IsEnabled() const { return mEnabled; }

    /** Set Actor Enabled
    * \param enabled New enabled status */
    void SetEnabled(bool enabled) { mEnabled = enabled; }

    /** Actor position
    * \returns position */
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** Set Actor position
    * \param pos New position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    /** Actor is clickable
    * \returns clickable status */
    bool IsClickable() const { return mClickable; }

    /** Set Actor clickable
    * \param clickable New clickable status */
    void SetClickable(bool clickable) { mClickable = clickable; }

    /** Get the picture we are drawing the actor in
    * \returns picture */
    CPicture* GetPicture() const { return mPicture; }

    /** The position animation channel
    * \returns Pointer to animation channel */
    CAnimChannelPoint* GetPositionChannel() { return &mChannel; }

    void SetPicture(CPicture* pic);

    void SetTimeline(CTimeline* timeline);

    void SetKeyframe();

    void GetKeyframe();

    void RemoveKeyframe();

private:
    /// Name of the actor
    std::wstring mName;

    /// Is the actor enabled
    bool mEnabled = true;

    /// The location of the actor
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);

    ///Is the actor clickable
    bool mClickable = true;

    /// The Root drawable
    std::shared_ptr<CDrawable> mRoot;

    /// The drawables in drawing order
    std::vector<std::shared_ptr<CDrawable>> mDrawablesInOrder;

    /// The picture the actor is in
    CPicture* mPicture = nullptr;

    /// The animation channel for animating the position of this drawable
    CAnimChannelPoint mChannel;

};

