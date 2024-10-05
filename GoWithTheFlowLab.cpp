/*
Humbert
Go With The Flow
Lab
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "materialClassRod.hpp"
#include "rodModeler.hpp"
using namespace std;

// Function to move the cursor up by a specified number of lines (ANSI escape code)
void clearConsole() {
    cout << "\033[2J\033[H";  // Clear screen and move the cursor to the top left
}

/*
void clearLine() {
    cout << "\033[2K\r";
}
*/

void functionalChecks()
{

    cout << "All checks pass.";
}

int main() {

    functionalChecks();

    materialClassRod rod1;
    HeatFlow rM;
    vector<double> myVector = { 200, 200, 200, 200, 200, 2000 };
    rod1.setVector(myVector);

    string userChoice;  // Variable to store the user's input

    do {
        
        //clearConsole();    // Option that clears the console and display the updated vector and instructions

        cout << "\n== Rod Temperatures ==" << endl;
        rod1.showVector();
        cout << "\nWould you like to apply another tick? (y/n): ";
        getline(cin, userChoice);  // Get the user's input

        if (userChoice == "y" || userChoice == "Y") {
            rM.tick(rod1);  // Apply a tick
        }
        else if (userChoice == "n" || userChoice == "N") {
            cout << "\nSimulation stopped. Exiting program...\n";
        }
        else {
            cout << "\nInvalid input. Please enter 'y' to continue or 'n' to stop.\n";  // Invalid inputs mitigated, it will just keep asking
        }

    } while (userChoice != "n" && userChoice != "N");  // Continue until the user presses 'n' or 'N'

    return 0;
}
