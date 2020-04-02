/**
 * \file Animal.h
 *
 * \author Ethan Clifford
 *
 * Declaration of the CAnimal class
 */

#pragma once

/**
 * Class that describes an Animal
 */
class CAnimal
{
public:
    virtual ~CAnimal();

    /** Display an animal. */
    virtual void DisplayAnimal() {}

    /** Determine if an animal is a defender
    *
    * \return false since the animals implemented handle determining if they are defenders or not.
    */
    virtual bool IsDefender() { return false; }
};

