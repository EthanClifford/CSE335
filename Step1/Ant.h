/**
 * \file Ant.h
 *
 * \author Ethan Clifford
 *
 * Class that describes an Ant.
 *
 * This class holds information about an Ant such as code and type.
 */

#pragma once

#include <string>
#include "Animal.h"

 /**
  * Class that describes an Ant
  *
  * Holds the code and type of an Ant
  */
class CAnt : public CAnimal
{
public:
    /// The types of ant we can have on our farm
    enum Type { WorkerAnt, SoldierAnt, Drone, Queen };

    void ObtainAntInformation();

    void DisplayAnimal();

    bool IsDefender();

private:
    /// The ant's code, which is a string of 3 capital letters
    std::string mCode;

    /// The type of ant: WorkerAnt, SoldierAnt, Drone, or Queen
    Type mType = WorkerAnt;

};

