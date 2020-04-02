/**
 * \file Farm.cpp
 *
 * \author Ethan Clifford
 */

#include <iostream>
#include "Farm.h"
#include "leak.h"

using namespace std;

/** Add an animal to the farm inventory.
*
* \param animal An animal to add to the inventory
*/
void CFarm::AddAnimal(CAnimal* animal)
{
    mInventory.push_back(animal);
}

/**
 * Display the farm inventory.
 */
void CFarm::DisplayInventory()
{
    for (auto animal : mInventory)
    {
        animal->DisplayAnimal();
    }
}


/**
 * Determine the number of defenders and display that number
 */
void CFarm::NumberOfDefenders()
{
    int NumDefenders = 0;
    for (auto animal : mInventory)
    {
        if (animal->IsDefender())
        {
            // If the animal is a defender, we increase NumDefenders by 1
            // to indicate another defender.
            NumDefenders += 1;
        }
    }
    cout << "There are " << NumDefenders << " Defenders." << endl;
}

/**
 * Destructor for this class
 */
CFarm::~CFarm()
{
    // Iterate over all of the animals, destroying each one.
    for (auto animal : mInventory)
    {
        delete animal;
    }

    // And clear the list
    mInventory.clear();
}