/**
 * \file PictureObserver.h
 *
 * \author Ethan Clifford
 *
 * Observer base class for a picture.
 */

#pragma once
#include <memory>
class CPicture;

 /**
  * Observer base class for a picture.
  *
  * This class implements the base class functionality for
  * an observer in the observer pattern.
  */
class CPictureObserver
{
public:
    virtual ~CPictureObserver();

    /// Copy Constructor (Disabled)
    CPictureObserver(const CPictureObserver&) = delete;

    /// Assignment Operator (Disabled)
    void operator=(const CPictureObserver&) = delete;

    /// This function is called to update any observers
    virtual void UpdateObserver() = 0;
    
    /** Getter for mPicture
    * \returns Pointer to the picture */
    std::shared_ptr<CPicture> GetPicture() { return mPicture; }

    void SetPicture(std::shared_ptr<CPicture> picture);

protected:
    /// Constructor
    CPictureObserver() {};

private:
    /// Picture we are observing
    std::shared_ptr<CPicture> mPicture;
};

