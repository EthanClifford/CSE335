/**
 * \file Cow.h
 *
 * \author Ethan Clifford
 *
 * Class that describes a Cow.
 *
 * This class holds information about a Cow such as name, type, and milk production.
 */

#pragma once

#include <string>
#include "Animal.h"

/**
 * Class that describes a Cow
 *
 * Holds the name, type, and milk production of a Cow
 */
class CCow : public CAnimal
{
public:
    /// The types of cow we can have on our farm
    enum Type {Bull, BeefCow, MilkCow};

    void ObtainCowInformation();

    void DisplayAnimal();

    bool IsDefender();

private:
    /// The cow's name
    std::string mName;

    /// The type of cow: Bull, BeefCow, or MilkCow
    Type mType = MilkCow;

    /// The milk production for a cow in gallons per day
    double mMilkProduction = 0;
};

