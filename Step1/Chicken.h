/**
 * \file Chicken.h
 *
 * \author Ethan Clifford
 *
 * Declaration of the CChicken class
 */

#pragma once

#include <string>
#include "Animal.h"

/**
 * Class that describes a chicken
 */
class CChicken : public CAnimal
{
public:
    void ObtainChickenInformation();

    void DisplayAnimal();

    bool IsDefender();

private:
    //! The chicken's ID
    std::string mId;
};

