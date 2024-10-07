/*
Humbert
Go With The Flow
Lab
* Uncomment the clearConsole function in the Interactive Sample area for a satisfying experience. *
*/

#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include "rodModeler.hpp"
using namespace std;


void clearConsole() {
    cout << "\033[2J\033[H";  // Clear screen and move the cursor to the top left
}

/*
void clearLine() {
    cout << "\033[2K\r";
}
*/

int main() {
    //------------------------------------------------------------
    //////////////////      TEST AREA    ////////////////////////
    //----------------------------------------------------------
    HeatFlow hTest(4, 0.05, 100, 0);
    assert(hTest.getVectorElement(0) == 100);
    assert(hTest.getVectorSize() == 4);
    assert(hTest.getK() == 0.05);
    assert(hTest.getTi() == 100);
    assert(hTest.getSinks() == 0);
    cout << "\n-> All assert checks passed.\n";

    cout << "\nUnit tests running:";
    cout << "\nVerify start point = 100 100 100 100";
    hTest.test_print();
    hTest.tick();
    cout << "\nTick operation performed, verify values = 108.65 100 100 108.65";
    hTest.test_print();
    hTest.tick();
    hTest.tick();
    hTest.tick();
    cout << "\n3 tick operation performed, verify values = 129.828 102.344 102.344 129.828";
    hTest.test_print();   
    cout << "\n\n-> User, please verify test values match expectations.";
   
    
    /////////////////////////////////////////////////////////////

    //------------------------------------------------------------
    /////////// Interactive Sample Sim Area /////////////////////
    //---------------------------------------------------------

    HeatFlow rod1;         //exammple of a rod going

    vector<double> myVector = { 300, 300, 300, 300, 300, 600 };
    rod1.setVector(myVector);

    string userChoice;  // Variable to store the user's input

    int lengthR = 0;
    double K = 1;
    double Ti = 0;
    int sinkN = 0;
    cout << "\n\n[Program Starting with sample simulation]\n\nRod Length: " << rod1.getVectorSize() << "\n\n";
    cout << "\nWould you like to apply sources or sinks? (y/anything else is no): ";
    string sourcesandsinksanswer;
    getline(cin, sourcesandsinksanswer);

    if (sourcesandsinksanswer == "y")
    {
        cout << "\nHow many? Input an integer greater than or equal to 0: ";
        int numberS;
        cin >> numberS;
        while (cin.fail() || numberS < 0) {
            cin.clear();
            cin.ignore();
            cout << "\nInvalid input. Please try again: ";
            cin >> numberS;
        }
        rod1.setSinks(numberS);
        cout << "\nProceeding to specify sources and sinks.";
    }
    else {
        sourcesandsinksanswer = "n";
        cout << "\nPress Enter to proceed. ";
    }
    
   
    
    rod1.ObtainandApplySinksandSources(); // Option to apply sinks and sources to the specified rod.
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Protects next cin input from left over new line characters after using the getline function.

    do {
        
        //clearConsole();    // Optional function that clears the console and display the updated vector and instructions
   
        cout << "\n\n== Rod Temp Sim (in Kelvin) ==\n";
        rod1.pretty_print();
        
        cout << "\nWould you like to apply a tick? (y/n): ";
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

    ////////////////////////////////////////////////////////////

    return 0;
}
