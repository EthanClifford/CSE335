/**
 * \file Chicken.cpp
 *
 * \author Ethan Clifford
 */

#include <iostream>
#include "Chicken.h"
#include "leak.h"

using namespace std;
/**
 * Obtain a chicken description from the user.
 */
void CChicken::ObtainChickenInformation()
{
    cout << endl;
    cout << "Input information about the chicken" << endl;

    // Obtain the ID. This is easy, since it's just a string.
    cout << "Id: ";
    cin >> mId;
}

/**
 * Display the chicken.
 */
void CChicken::DisplayAnimal()
{
    cout << "Chicken: " << mId << endl;
}

/**
 * Determines if a chicken is a defender.
 *
 * \returns false because no chickens are defenders
 */
bool CChicken::IsDefender()
{
    return false;
}
