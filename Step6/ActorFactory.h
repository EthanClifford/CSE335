/**
 * \file ActorFactory.h
 *
 * \author Ethan Clifford
 *
 * Base class for actor factories.
 */

#pragma once
#include <memory>

class CActor;

 /**
  * Abstract base class for actor factories.
  */
class CActorFactory
{
public:
    /** Creates actors
    * \returns Pointer to the actor created */
    virtual std::shared_ptr<CActor> Create() = 0;
};

