/**
 * \file Timeline.cpp
 *
 * \author Ethan Clifford
 */

#include "pch.h"
#include "Timeline.h"
#include "AnimChannel.h"

/**
* Constructor
*/
CTimeline::CTimeline()
{

}

/** Adds a channel to the timeline
* \param channel The channel to be added
*/
void CTimeline::AddChannel(CAnimChannel* channel)
{
    mChannels.push_back(channel);
    channel->SetTimeline(this);
}

/** Sets the current time
*
* Ensures all of the channels are
* valid for that point in time.
*
* \param t The current time
*/
void CTimeline::SetCurrentTime(double t)
{
    // Set the time
    mCurrentTime = t;

    for (auto channel : mChannels)
    {
        channel->SetFrame(GetCurrentFrame());
    }
}