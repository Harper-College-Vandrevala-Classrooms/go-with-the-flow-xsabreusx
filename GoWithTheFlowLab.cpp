// Humbert
// Go With The Flow
//

#include <iostream>
#include <vector>
#include "materialClassRod.hpp"
#include "rodModeler.hpp"
using namespace std;

// Function to move the cursor up by a specified number of lines (ANSI escape code)
void clearConsole() {
    cout << "\033[2J\033[H";  // Clear screen and move the cursor to the top left
}

// Function to clear the current line (ANSI escape code)
void clearLine() {
    cout << "\033[2K\r";
}

int main() {
    materialClassRod rod1;
    rodModeler rM;
    vector<double> myVector = { 200, 200, 200, 200, 200, 2000 };
    rod1.setVector(myVector);

    char userChoice;  // Variable to store the user's input

    do {
        // Clear the console and display the updated vector and instructions
        clearConsole();

        cout << "\n== Rod Temperatures ==" << endl;
        rod1.showVector();
        cout << "\nWould you like to apply another tick? (y/n): ";
        cin >> userChoice;  // Get the user's input

        if (userChoice == 'y' || userChoice == 'Y') {
            rM.tick(rod1);  // Apply a tick operation
        }
        else if (userChoice == 'n' || userChoice == 'N') {
            cout << "\nSimulation stopped. Exiting program...\n";
        }
        else {
            cout << "\nInvalid input. Please enter 'y' to continue or 'n' to stop.\n";
        }

    } while (userChoice != 'n' && userChoice != 'N');  // Continue until the user presses 'n' or 'N'

    return 0;
}
