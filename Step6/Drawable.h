/**
 * \file Drawable.h
 *
 * \author Ethan Clifford
 *
 * Abstract base class for drawable elements of our picture.
 */

#pragma once
#include <string>
#include <memory>
#include <vector>
#include "AnimChannelAngle.h"

class CActor;
class CTimeline;
 
/**
* Abstract base class for drawable elements of our picture.
*
* A drawable is one part of an actor. Drawable parts can be moved
* independently.
*/
class CDrawable
{
public:
    /** \brief Default constructor disabled */
    CDrawable() = delete;
    /** \brief Copy constructor disabled */
    CDrawable(const CDrawable &) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CDrawable &) = delete;

    virtual ~CDrawable();

    void SetActor(CActor *actor);

    /** Draws the drawable
    * \param graphics The graphics to draw in */
    virtual void Draw(Gdiplus::Graphics* graphics) = 0;
    
    void Place(Gdiplus::Point offset, double rotate);
    
    void AddChild(std::shared_ptr<CDrawable> child);
    
    /** Checks if the drawable has been hit
    * \param pos The position that we are checking for a collision at
    * \returns true if there is a collision, false otherwise
    */
    virtual bool HitTest(Gdiplus::Point pos) = 0;
    
    /** Is the drawable moveable
    * \return false because only the head is moveable */
    virtual bool IsMoveable() { return false; }
    
    void Move(Gdiplus::Point delta);

    /**
    * Gets the name of the drawable
    * \return The string that contains the drawable's name
    */
    std::wstring GetName() const { return mName; }

    /** Drawable's position
    * \returns position */
    Gdiplus::Point GetPosition() const { return mPosition; }

    /** Set Drawable's position
    * \param pos New position */
    void SetPosition(Gdiplus::Point pos) { mPosition = pos; }

    /** Drawable's rotation
    * \returns rotation */
    double GetRotation() const { return mRotation; }

    /** Set Drawable's rotation
    * \param rot New rotation */
    void SetRotation(double rot) { mRotation = rot; }

    /** Drawable's parent
    * \returns parent of drawable */
    CDrawable* GetParent() { return mParent; }

    /** Set Drawable's parent
    * \param parent New parent */
    void SetParent(CDrawable* parent) { mParent = parent; }

    virtual void SetTimeline(CTimeline* timeline);

    /** The angle animation channel
    * \returns Pointer to animation channel */
    CAnimChannelAngle* GetAngleChannel() { return &mChannel; }

    virtual void SetKeyframe();

    virtual void GetKeyframe();

    virtual void RemoveKeyframe();

protected:
    CDrawable(const std::wstring& name);

    Gdiplus::Point RotatePoint(Gdiplus::Point point, double angle);

    /// The position that the drawable is placed at
    Gdiplus::Point mPlacedPosition = Gdiplus::Point(0, 0);
    
    /// The amount that the drawable is rotated by
    double mPlacedR = 0;

private:
    /// The position of the drawable
    Gdiplus::Point mPosition = Gdiplus::Point(0, 0);
    
    /// The name of the drawable
    std::wstring mName;

    /// The rotation of the drawable
    double mRotation = 0;

    /// The actor using this drawable
    CActor* mActor = nullptr;

    /// The children of this drawable
    std::vector<std::shared_ptr<CDrawable>> mChildren;

    /// The parent of this drawable
    CDrawable* mParent = nullptr;

    /// The animation channel for animating the angle of this drawable
    CAnimChannelAngle mChannel;
};

