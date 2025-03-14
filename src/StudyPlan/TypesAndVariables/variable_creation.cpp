
#include <iostream>
#include <string>

using namespace std;

namespace VariableCreation {
    void run() {
        /*
        This file will show how comments work
        and how to declare and initialize basic types
        */

        // Integer values
        int MaxLife{150};
        int Health{MaxLife}; // We initialize it wiht another variable's value
        int Level{1};

        // Boolean value
        bool /* This comment is inside of the statement */ isAlive{true};

        // String value
        string Name{"King Arthur"};

        // Float value
        float Armor{0.5};

        // Outputing variables
        cout << "The character's name is " << Name;
        cout << ",\nits health is " << Health;
        cout << " and its level is " << Level << endl;
    }
}