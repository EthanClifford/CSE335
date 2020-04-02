/**
 * \file AnimChannelAngle.h
 *
 * \author Ethan Clifford
 *
 * Animation channel for angles
 */

#pragma once
#include "AnimChannel.h"


/**
 * Animation channel for angles.
 */
class CAnimChannelAngle : public CAnimChannel
{
public:
    CAnimChannelAngle();

    /** \brief Copy constructor disabled */
    CAnimChannelAngle(const CAnimChannelAngle&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CAnimChannelAngle&) = delete;

    virtual ~CAnimChannelAngle();

    void SetKeyframe(double angle);

    /** Gets the angle of the channel
    * \return The angle of the channel
    */
    double GetAngle() { return mAngle; }

    /** Class that represents a keyframe for angles */
    class KeyframeAngle : public Keyframe
    {
    public:
        /** Constructor
        * \param channel The channel we are for
        * \param angle The angle for the keyframe */
        KeyframeAngle(CAnimChannelAngle* channel, double angle) :
            Keyframe(channel), mChannel(channel), mAngle(angle) {}

        /** \brief Default constructor disabled */
        KeyframeAngle() = delete;
        /** \brief Copy constructor disabled */
        KeyframeAngle(const KeyframeAngle&) = delete;
        /** \brief Assignment operator disabled */
        void operator=(const KeyframeAngle&) = delete;

        /** Use this keyframe as keyframe 1 */
        void UseAs1() override { mChannel->mKeyframe1 = this; }

        /** Use this keyframe as keyframe 2 */
        void UseAs2() override { mChannel->mKeyframe2 = this; }

        /** Use this keyframe as the angle */
        void UseOnly() override { mChannel->mAngle = mAngle; }

        /** Gets the angle that the keyframe is set at
        * \return The angle of the keyframe */
        double GetAngle() { return mAngle; }

    private:
        /// The angle that the keyframe is set at
        double mAngle;

    private:
        /// The channel this keyframe is associated with
        CAnimChannelAngle* mChannel;
    };

protected:
    void Tween(double t) override;

private:
    /// The angle that the channel is set at
    double mAngle = 0;

    /// The first angle keyframe
    KeyframeAngle* mKeyframe1 = nullptr;

    /// The second angle keyframe
    KeyframeAngle* mKeyframe2 = nullptr;
};

