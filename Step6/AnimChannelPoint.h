/**
 * \file AnimChannelPoint.h
 *
 * \author Ethan Clifford
 *
 * Animation channel for points
 */

#pragma once
#include "AnimChannel.h"


/**
 * Animation channel for points
 */
class CAnimChannelPoint : public CAnimChannel
{
public:
    CAnimChannelPoint();

    /** \brief Copy constructor disabled */
    CAnimChannelPoint(const CAnimChannelPoint&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CAnimChannelPoint&) = delete;

    virtual ~CAnimChannelPoint();

    void SetKeyframe(Gdiplus::Point p);

    /** Gets the position of this channel
    * \return The position of the channel */
    Gdiplus::Point GetPosition() { return mPoint; }

    /** Class that represents a keyframe for points */
    class KeyframePoint : public Keyframe
    {
    public:
        /** Constructor
        * \param channel The channel we are for
        * \param p The Point for the keyframe */
        KeyframePoint(CAnimChannelPoint* channel, Gdiplus::Point p) :
            Keyframe(channel), mChannel(channel), mPoint(p) {}

        /** \brief Default constructor disabled */
        KeyframePoint() = delete;
        /** \brief Copy constructor disabled */
        KeyframePoint(const KeyframePoint&) = delete;
        /** \brief Assignment operator disabled */
        void operator=(const KeyframePoint&) = delete;

        /** Use this keyframe as keyframe 1 */
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyframe 2 */
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the Point */
        void UseOnly() override { mChannel->mPoint = mPoint; }

        /** Gets the location the keyframe is set at
        * \return The location the keyframe is set at */
        Gdiplus::Point GetPoint() { return mPoint; }

    private:
        /// The location that the keyframe is set at
        Gdiplus::Point mPoint;

    private:
        /// The channel this keyframe is associated with
        CAnimChannelPoint* mChannel;
    };

protected:
    void Tween(double t) override;

private:
    /// The location that the channel is set at
    Gdiplus::Point mPoint;

    /// The first Point keyframe
    KeyframePoint* mKeyframe1 = nullptr;

    /// The second Point keyframe
    KeyframePoint* mKeyframe2 = nullptr;
};

