/**
 * \file ViewTimeline.cpp
 *
 * \author Ethan Clifford
 */


#include "pch.h"
#include <sstream>
#include "CanadianExperience.h"
#include "ViewTimeline.h"
#include "DoubleBufferDC.h"
#include "MainFrm.h"
#include "Timeline.h"
#include "Picture.h"
#include "Actor.h"

using namespace std;
using namespace Gdiplus;


IMPLEMENT_DYNCREATE(CViewTimeline, CScrollView)

/// The window height in pixels
const int WindowHeight = 60;

/// The spacing from the top of the 
/// window to the top of the tick marks in pixels
const int BorderTop = 20;

/// Space to the left of the scale in pixels
const int BorderLeft = 10;

/// Space to the right of the scale in pixels
const int BorderRight = 10;

/// The spacing between ticks on the timeline in pixels
const int TickSpacing = 3;

/// The length of a short tick mark in pixels
const int TickShort = 10;

/// The length of a long tick mark in pixels
const int TickLong = 20;

/** Constructor */
CViewTimeline::CViewTimeline()
{
    mPointer = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/pointer-down.png"));
    assert(mPointer->GetLastStatus() == Ok);
}

/** Destructor */
CViewTimeline::~CViewTimeline()
{
}




/** Handle the initial update for this window */
void CViewTimeline::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

    int sbHeight = GetSystemMetrics(SM_CXHSCROLL);
    CSize sizeTotal(200, Height - sbHeight - 20);
	SetScrollSizes(MM_TEXT, sizeTotal);
}

/** Draw this window 
 * \param pDC Device context */
void CViewTimeline::OnDraw(CDC* pDC)
{
    // Get the timeline
    CTimeline* timeline = GetPicture()->GetTimeline();

    // Set the scroll system correctly
    CSize sizeTotal(timeline->GetNumFrames() * TickSpacing + BorderLeft + BorderRight, WindowHeight);
    SetScrollSizes(MM_TEXT, sizeTotal);

    CDoubleBufferDC dbDC(pDC);

    Graphics graphics(dbDC.m_hDC);    // Create GDI+ graphics context

    Pen pen(Color(0, 0, 0), 1);
    // TODO: Drawing code goes here

    SolidBrush brush(Color(0, 0, 0));
    // TODO: Drawing code goes here

    CRect rect;
    GetClientRect(&rect);
    int hit = rect.Height();
    int wid = rect.Width();
    int x = BorderLeft;
    for (int tickNum = 0; tickNum < timeline->GetNumFrames(); tickNum += 1)
    {
        
        bool onSecond = (tickNum % timeline->GetFrameRate()) == 0;
        if (onSecond)
        {
            graphics.DrawLine(&pen, Point(x, BorderTop), Point(x, BorderTop + TickLong));
            // Convert the tick number to seconds in a string
            std::wstringstream str;
            str << tickNum / timeline->GetFrameRate();
            std::wstring wstr = str.str();

            FontFamily fontFamily(L"Arial");
            Gdiplus::Font font(&fontFamily, 16);

            RectF size;
            PointF origin(0.0f, 0.0f);
            graphics.MeasureString(wstr.c_str(), wstr.size(),
                &font, origin, &size);
            graphics.DrawString(wstr.c_str(), -1, &font, PointF(origin.X + x - (int)size.Width / 2, origin.Y + ((int) size.Height / 2) + TickLong), &brush);
        }
        else
        {
            graphics.DrawLine(&pen, Point(x, BorderTop), Point(x, BorderTop + TickShort));
        }
        
        x += TickSpacing;
    }

    auto state = graphics.Save();
    graphics.DrawImage(mPointer.get(), (timeline->GetCurrentTime() * timeline->GetFrameRate()) * TickSpacing + BorderLeft - (mPointer->GetWidth() / 2), 
        BorderTop, mPointer->GetWidth(), mPointer->GetHeight());
    graphics.Restore(state);
}


/** Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context 
 * \return FALSE */
BOOL CViewTimeline::OnEraseBkgnd(CDC* pDC)
{
    return FALSE;
}

/** Handle the Edit>Set Keyframe menu option */
 void CViewTimeline::OnEditSetkeyframe()
 {
     for (auto actor : *GetPicture())
     {
         actor->SetKeyframe();
     }
 }


 /** Handle the Edit>Delete Keyframe menu option */
 void CViewTimeline::OnEditDeletekeyframe()
 {
     for (auto actor : *GetPicture())
     {
         actor->RemoveKeyframe();
     }
     GetPicture()->SetAnimationTime(GetPicture()->GetTimeline()->GetCurrentTime());
 }

/**
* Force an update of this window when the picture changes.
*/
 void CViewTimeline::UpdateObserver()
 {
     Invalidate();
     UpdateWindow();
 }


 // Doxygen sometimes gets confused by these message 
 // maps, since they look like functions. I've found
 // it helps to move them to the end of the file.
 BEGIN_MESSAGE_MAP(CViewTimeline, CScrollView)
	 ON_WM_CREATE()
	 ON_WM_ERASEBKGND()
	 ON_COMMAND(ID_EDIT_SETKEYFRAME, &CViewTimeline::OnEditSetkeyframe)
	 ON_COMMAND(ID_EDIT_DELETEKEYFRAME, &CViewTimeline::OnEditDeletekeyframe)
     ON_WM_LBUTTONDOWN()
     ON_WM_MOUSEMOVE()
 END_MESSAGE_MAP()

 /** Tells if the Left mouse buttun is depressed
 * \param nFlags The neccessary flags
 * \param point The point that the mouse is at */
 void CViewTimeline::OnLButtonDown(UINT nFlags, CPoint point)
 {
     // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);
     // TODO: Add your message handler code here and/or call default

     int x = point.x;
     int y = point.y;

     // Get the timeline
     CTimeline* timeline = GetPicture()->GetTimeline();
     int pointerX = (int)(timeline->GetCurrentTime() * timeline->GetFrameRate() * TickSpacing + BorderLeft);

     mMovingPointer = x >= pointerX - (int)mPointer->GetWidth() / 2 && x <= pointerX + (int)mPointer->GetWidth() / 2;
     mMovingPointer = mMovingPointer && y <= BorderTop + (int)mPointer->GetHeight() && y >= BorderTop;


     __super::OnLButtonDown(nFlags, point);
 }

 /** Determines what happens when the mouse moves
 * \param nFlags The necessary flags
 * \param point The point that the mouse is at
 */
 void CViewTimeline::OnMouseMove(UINT nFlags, CPoint point)
 {
     // Convert mouse coordinates to logical coordinates
     CClientDC dc(this);
     OnPrepareDC(&dc);
     dc.DPtoLP(&point);
     // TODO: Add your message handler code here and/or call default
     CTimeline* timeline = GetPicture()->GetTimeline();
     double x = point.x;

     double time = (x - BorderLeft) / (timeline->GetFrameRate() * TickSpacing);

     double numTicksFromDuration = 1.0;
     if (nFlags && MK_LBUTTON)
     {
         if (x < BorderLeft && mMovingPointer)
         {
             GetPicture()->SetAnimationTime(0);
             GetPicture()->UpdateObservers();
         }
         else if (mMovingPointer && time > timeline->GetDuration())
         {
             GetPicture()->SetAnimationTime(timeline->GetDuration() - (numTicksFromDuration / timeline->GetFrameRate()));
             GetPicture()->UpdateObservers();
         }
         else if (mMovingPointer)
         {
             GetPicture()->SetAnimationTime(time);
             GetPicture()->UpdateObservers();
         }
     }

     __super::OnMouseMove(nFlags, point);
 }
