/**
 * \file Ant.cpp
 *
 * \author Ethan Clifford
 */

#include <iostream>
#include <cctype>
#include "Ant.h"
#include "leak.h"

using namespace std;

/**
 * Obtain an ant description from the user.
 */
void CAnt::ObtainAntInformation()
{
    cout << endl;
    cout << "Input information about the ant" << endl;
    
    // Obtain the code.  This is easy since it's just a string.
    // We do have to check that the code is valid
    bool done = false;
    while (!done)
    {
        cout << "Code: ";
        cin >> mCode;
        int CodeLength = 3;
        if (mCode.length() == CodeLength)
        {
            // The code has the right length, so now we need to
            // check that all letters are upper case
            int i = 0;
            while (i < CodeLength)
            {
                // Loops through mCode and makes sure each element is an 
                // upper case letter.
                if (!isupper(mCode[i]))
                {
                    break;
                }
                i += 1;
            }

            if (i == CodeLength)
            {
                // If i is the same as CodeLength, then every letter is upper case.
                // We therefore have a valid code.
                done = true;
            }
            else
            {
                // We have an error. Clear the input and try again
                cout << "Invalid input" << endl;
                cin.clear();
                cin.ignore();
            }

        }
        else
        {
            // We have an error. Clear the input and try again
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore();
        }
    }

    // Now we obtain the type of the ant
    done = false;
    while (!done)
    {
        cout << "1: Worker Ant" << endl;
        cout << "2: Soldier Ant" << endl;
        cout << "3: Drone" << endl;
        cout << "4: Queen" << endl;
        cout << "Enter selection and return: ";
        int option;
        cin >> option;
        if (!cin)
        {
            // We have an error.  Clear the input and try again
            cout << "Invalid input" << endl;
            cin.clear();
            cin.ignore();
            continue;
        }

        switch (option)
        {
        case 1:
            mType = WorkerAnt;
            done = true;
            break;

        case 2:
            mType = SoldierAnt;
            done = true;
            break;

        case 3:
            mType = Drone;
            done = true;
            break;

        case 4:
            mType = Queen;
            done = true;
            break;

        }
    }
}

/**
 * Display the ant.
 */
void CAnt::DisplayAnimal()
{
    cout << "Ant " << mCode << " is a ";
    switch (mType)
    {
    case WorkerAnt:
        cout << "Worker Ant" << endl;
        break;

    case SoldierAnt:
        cout << "Soldier Ant" << endl;
        break;

    case Drone:
        cout << "Drone" << endl;
        break;

    case Queen:
        cout << "Queen" << endl;
        break;
    }
    
}

/**
 * Determines if an ant is a defender, which are only the Soldier Ants
 *
 * \returns true if the ant is a SoldierAnt, false otherwise
 */
bool CAnt::IsDefender()
{
    if (mType == SoldierAnt)
    {
        return true;
    }
    return false;
}
