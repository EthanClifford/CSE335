/**
 * \file SpartyFactory.h
 *
 * \author Ethan Clifford
 *
 * Factory class that builds the Sparty character
 */

#pragma once
#include "ActorFactory.h"
/**
 * Factory class that builds the Sparty character
 */
class CSpartyFactory : public CActorFactory
{
public:
	virtual std::shared_ptr<CActor> Create() override;
};

