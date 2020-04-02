/**
 * \file HeadTop.h
 *
 * \author Ethan Clifford
 *
 * The drawable for the top of the head
 */

#pragma once
#include "ImageDrawable.h"
/**
 * The class that implements the drawable for the top of the head
 */
class CHeadTop : public CImageDrawable
{
public:
	CHeadTop(const std::wstring& name, const std::wstring& filename);

    /** \brief Default constructor disabled */
    CHeadTop() = delete;
    /** \brief Copy constructor disabled */
    CHeadTop(const CHeadTop&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CHeadTop&) = delete;

	void Draw(Gdiplus::Graphics* graphics) override;
    
    /** Is the drawable moveable
    * \returns true */
    bool IsMoveable() override { return true; }

    Gdiplus::Point TransformPoint(Gdiplus::Point p);

    void DrawEyebrow(Gdiplus::Graphics* graphics, Gdiplus::Point point);

    void DrawEye(Gdiplus::Graphics* graphics, Gdiplus::Point point);

    /** Set how much the Left Eye is offset from center by
    * \param p The amount the drawable is offset by */
    void SetLeftEyeOffset(Gdiplus::Point p) { mLeftEyeOffset = p; }

    /** Set how much the Right Eye is offset from center by
    * \param p The amount the drawable is offset by */
    void SetRightEyeOffset(Gdiplus::Point p) { mRightEyeOffset = p; }

    /** Set how much the Left Eyebrow is offset from center by
    * \param p The amount the drawable is offset by */
    void SetLeftEyebrowOffset(Gdiplus::Point p) { mLeftEyebrowOffset = p; }

    /** Set how much the Right Eyebrow is offset from center by
    * \param p The amount the drawable is offset by */
    void SetRightEyebrowOffset(Gdiplus::Point p) { mRightEyebrowOffset = p; }

private:
    /// The amount the Left Eye is offset by from center
    Gdiplus::Point mLeftEyeOffset = Gdiplus::Point(0, 0);

    /// The amount the Right Eye is offset by from center
    Gdiplus::Point mRightEyeOffset = Gdiplus::Point(0, 0);

    /// The amount the Left Eyebrow is offset by from center
    Gdiplus::Point mLeftEyebrowOffset = Gdiplus::Point(0, 0);

    /// The amount the Right Eyebrow is offset by from center
    Gdiplus::Point mRightEyebrowOffset = Gdiplus::Point(0, 0);
};

