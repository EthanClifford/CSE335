/**
 * \file HaroldFactory.h
 *
 * \author Ethan Clifford
 *
 * Factory class that builds the Harold character
 */

#pragma once
#include "ActorFactory.h"
 
/**
* Factory class that builds the Harold character
*/
class CHaroldFactory : public CActorFactory
{
public:
    virtual std::shared_ptr<CActor> Create() override;
};

