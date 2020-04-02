/**
 * \file Picture.h
 *
 * \author Ethan Clifford
 *
 * The picture we are drawing 
 */

#pragma once
#include <vector>
#include <memory>
#include "Timeline.h"

class CPictureObserver;
class CActor;

/**
* The picture we are drawing.
*
* There will be one picture object that contains all of
* our actors, which then contains the drawables.
*/
class CPicture
{
public:
    /// constructor
    CPicture() {};

    /// Copy Constructor (Disabled)
    CPicture(const CPicture&) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const CPicture&) = delete;

    /** The picture size
    * \returns Size */
    Gdiplus::Size GetSize() { return mSize; }

    /** The picture size
    * \param size The new picture size */
    void SetSize(Gdiplus::Size size) { mSize = size; }

    void AddObserver(CPictureObserver* observer);
    void RemoveObserver(CPictureObserver* observer);
    void UpdateObservers();
    void Draw(Gdiplus::Graphics* graphics);
    void AddActor(std::shared_ptr<CActor> actor);

    void SetAnimationTime(double time);

    /** Iterator that iterates over actors in the picture */
    class Iter
    {
    public:
        /** Constructor
        * \param pic The picutre we are iterating over
        * \param pos The position that we are currently at
        */
        Iter(CPicture* pic, int pos) : mPicture(pic), mPos(pos) {}
        
        /** Test for the end of the iterator
        * \param other The other operand
        * \returns True if this position equals not equal to the other position */
        bool operator!=(const Iter& other) const
        {
            return mPos != other.mPos;
        }

        /** Get value at current position
        * \returns Value at mPos in the collection */
        std::shared_ptr<CActor> operator *() const { return mPicture->mActorsInOrder[mPos]; }
    
        /** Increment the iterator
        * \returns Value at mPos in the collection */
        const Iter& operator++()
        {
            mPos++;
            return *this;
        }

    private:
        CPicture* mPicture; ///< Picture we are iteration over
        int mPos;   ///< Position in the collection
    };

    /** Get an iterator for the beginning of the collection
    * \returns Iter object at position 0 */
    Iter begin() { return Iter(this, 0); }

    /** Get an iterator for the end of the collection
    * \returns Iter object at position past the end */
    Iter end() { return Iter(this, mActorsInOrder.size()); }

    /** Get a pointer to the Timeline object
    * \returns Pointer to the Timeline object
    */
    CTimeline* GetTimeline() { return &mTimeline; }

private:
    /// The picture size
    Gdiplus::Size mSize = Gdiplus::Size(800, 600);

    /// The observers of this picture
    std::vector<CPictureObserver*> mObservers;

    /// The actors in the order they are added
    std::vector<std::shared_ptr<CActor>> mActorsInOrder;

    /// The animation timeline
    CTimeline mTimeline;
};

