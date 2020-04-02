/**
 * \file AnimChannel.h
 *
 * \author Ethan Clifford
 *
 * Base class for animation channels
 */

#pragma once
#include <string>
#include <memory>
#include <vector>

class CTimeline;

/**
 * Base class for animation channels 
 *
 * This class provides basic functionality and a polymorphic
 * representation for animation channels. 
 */
class CAnimChannel
{
public:
    virtual ~CAnimChannel();
    CAnimChannel();

    
    /** \brief Copy constructor disabled */
    CAnimChannel(const CAnimChannel&) = delete;
    /** \brief Assignment operator disabled */
    void operator=(const CAnimChannel&) = delete;

    bool IsValid();

    void SetFrame(int currFrame);

    /** Sets the name of the channel 
    * \param name The name to be used as the new name
    */
    void SetName(std::wstring name) { mName = name; }

    /** Gets the name of the channel
    * \return The name of the channel
    */
    std::wstring GetName() { return mName; }

    /** Gets the Timeline being used
    * \return The timeline
    */
    CTimeline* GetTimeline() { return mTimeline; }

    /** Sets the timeline of the channel
    * \param timeline The timeline to be used
    */
    void SetTimeline(CTimeline* timeline) { mTimeline = timeline; }

    void RemoveKeyframe();

    /** Class that represents a keyframe */
    class Keyframe
    {
    public:
        /** \brief Default constructor disabled */
        Keyframe() = delete;
        /** \brief Copy constructor disabled */
        Keyframe(const Keyframe&) = delete;
        /** \brief Assignment operator disabled */
        void operator=(const Keyframe&) = delete;

        /** Pure virtual function that says that this keyframe should be 
        * used as the first keyframe to the left of the pointer */
        virtual void UseAs1() = 0;

        /** Pure virtual function that says that this keyframe should be
        * used as the first keyframe to the right of the pointer */
        virtual void UseAs2() = 0;

        /** Pure virtual function that says that this keyframe should be
        * used as the only keyframe */
        virtual void UseOnly() = 0;

        /** Sets the frame that the keyframe is at
        * \param frame The frame that we are setting the keyframe at
        */
        void SetFrame(int frame) { mFrame = frame; }

        /** Gets the frame that the keyframe is at
        * \return The frame that the keyframe is at
        */
        int GetFrame() { return mFrame; }

    protected:
        /** Constructor
        * \param channel Channel we are associated with */
        Keyframe(CAnimChannel* channel) : mChannel(channel) {}

        /// The frame that this keyframe is at
        int mFrame = 0;

    private:
        /// The channel this keyframe is associated with
        CAnimChannel* mChannel;
    };

protected:
    void InsertKeyframe(std::shared_ptr<Keyframe> keyframe);

    /** Pure virutal function to perform tweening
    * \param t The t-value for this tweening*/
    virtual void Tween(double t) = 0;

private:
    /// The name of the channel
    std::wstring mName;
    
    /// The Keyframe that is in the same spot as the pointer or to the left
    int mKeyframe1 = -1;

    /// The Keyframe that is to the right of the pointer
    int mKeyframe2 = -1;

    /// The timeline object
    CTimeline* mTimeline = nullptr;

    /// The collection of keyframes for this channel
    std::vector<std::shared_ptr<Keyframe>> mKeyframes;
};

