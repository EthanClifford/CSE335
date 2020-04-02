/**
 * \file TimelineDlg.h
 *
 * \author Ethan Clifford
 *
 * Dialog box for setting timeline information
 */

#pragma once

class CTimeline;
// CTimelineDlg dialog

/**
 * Class that implements the timeline dialog box
 */
class CTimelineDlg : public CDialog
{
	DECLARE_DYNAMIC(CTimelineDlg)

public:
	CTimelineDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CTimelineDlg();

	void SetTimeline(CTimeline* timeline);

	void Take();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TIMELINEDLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
private:
	/// The number of frames in the timeline
	int mNumFrames;

	/// The timeline we are editing
	CTimeline* mTimeline = nullptr;

	/// The frame rate of the timeline
	int mFrameRate;
};
