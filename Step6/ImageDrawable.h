/**
 * \file ImageDrawable.h
 *
 * \author Ethan Clifford
 *
 * An image that is drawable
 */

#pragma once
#include <string>
#include "Drawable.h"

/**
 * The class that implements a drawable that is an image
 */
class CImageDrawable : public CDrawable
{
public:
    CImageDrawable(const std::wstring &name, const std::wstring& filename);

    /** \brief Default constructor disabled */
    CImageDrawable() = delete;
    /** \brief Copy constructor disabled */
    CImageDrawable(const CImageDrawable&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CImageDrawable&) = delete;

    void Draw(Gdiplus::Graphics* graphics) override;

    bool HitTest(Gdiplus::Point pos) override;

    /** Get the center of the drawable
    * \returns Center */
    Gdiplus::Point GetCenter() { return mCenter; }

    /** Set the center of the drawable
    * \param cent The new center */
    void SetCenter(Gdiplus::Point cent) { mCenter = cent; }

protected:
    /// The image for this drawable
    std::unique_ptr<Gdiplus::Bitmap> mImage;

private:
    /// The center of this drawable
    Gdiplus::Point mCenter = Gdiplus::Point(0, 0);
};

