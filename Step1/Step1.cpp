/**
* \file Step1.cpp
*
* \author Ethan Clifford
*/

#include <iostream>
#include "Farm.h"
#include "Cow.h"
#include "leak.h"
#include "Chicken.h"
#include "Ant.h"

using namespace std;

/**
* Main entry point
*
* This is where the program starts.
* \return 0
*/
int main()
{
    // Support memory leak detection
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    cout << "Instantiating Farm" << endl;
    CFarm farm;

    //This loops continuously until we are done
    bool done = false;
    while (!done)
    {
        // Output user instructions
        cout << endl;
        cout << "Farm management" << endl;
        cout << "1 - Add cow" << endl;
        cout << "2 - Add chicken" << endl;
        cout << "3 - Add ant" << endl;
        cout << "9 - List inventory" << endl;
        cout << "50 - Number of Defenders" << endl;
        cout << "99 - Exit" << endl;
        cout << "Select Option: ";

        // Get option from the user
        int option;
        cin >> option;

        // Handle invalid input
        if (!cin)
        {
            option = 1000;
            cin.clear();
            cin.ignore();   // Discard bad input
        }

        // Handle the possible user options
        switch (option)
        {
        case 1:
            {
                cout << "Adding cow" << endl;
                CCow* cow = new CCow();
                cow->ObtainCowInformation();
                farm.AddAnimal(cow);
            }
            break;

        case 2:
            {
                cout << "Adding chicken" << endl;
                CChicken* chicken = new CChicken();
                chicken->ObtainChickenInformation();
                farm.AddAnimal(chicken);
            }
            break;

        case 3:
            {
                cout << "Adding ant" << endl;
                CAnt* ant = new CAnt();
                ant->ObtainAntInformation();
                farm.AddAnimal(ant);
            }
            break;

        case 9:
            farm.DisplayInventory();
            break;

        case 50:
            farm.NumberOfDefenders();
            break;
        
        case 99:
            done = true;
            break;

        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}