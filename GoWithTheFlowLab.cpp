/*
Humbert
Go With The Flow
Lab
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
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

int main() {
    //////////////////      TEST AREA    ////////////////////////

    vector <double> testVector = { 1, 2, 3, 4 };
    HeatFlow hTest;
    cout << "All checks pass.";

    /////////////////////////////////////////////////////////////
    






    /////////// Interactive Area /////////////////////

    HeatFlow rod1;

    vector<double> myVector = { 200, 200, 200, 200, 200, 2000 };
    rod1.setVector(myVector);

    string userChoice;  // Variable to store the user's input

    int lengthR = 0;
    double K = 1;
    double Ti = 0;
    int sinkN = 0;


    do {
        
        //clearConsole();    // Option that clears the console and display the updated vector and instructions

        cout << "\n== Rod Temperatures ==" << endl;
        rod1.pretty_print();
        cout << "\nWould you like to apply another tick? (y/n): ";
        getline(cin, userChoice);  // Get the user's input

        if (userChoice == "y" || userChoice == "Y") {
            rod1.tick();  // Apply a tick
        }
        else if (userChoice == "n" || userChoice == "N") {
            cout << "\nSimulation stopped. Exiting program...\n";
        }
        else {
            cout << "\nInvalid input. Please enter 'y' to continue or 'n' to stop.\n";  // Invalid inputs mitigated, it will just keep asking
        }

    } while (userChoice != "n" && userChoice != "N");  // Continue until the user presses 'n' or 'N'

    //////////////////////////////////////////////////

    return 0;
}
