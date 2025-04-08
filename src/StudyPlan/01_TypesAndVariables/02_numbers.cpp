#include <iostream>

namespace Numbers {

    void run() {
        // Basic variables reminder
        bool isDead{false};
        int Level{5};
        float Armor{0.2};
        int coinsOwned{100'000'000}; // We can use single quote
                                    // character for better readability
        /////////////////////////////
        // Basic arithmetic operators

        // Level is updated with the value of 10
        Level = 5 * 2;
        Level = 5 + 1; // Level is 6
        Level = 5 - 1; // Level is 4
        Level = 5 * 2; // Level is 10
        Level = 6 / 2; // Level is 3
        Level = 1 + 2 + 3; // Level is 6

        /////////////////////////////
        // Order of operations

        // Level is updated with a value of 7
        Level =  1 + 2 * 3;
        // Level is updated with a value of 9
        Level =  (1 + 2) * 3;

        /////////////////////////////
        // Variables with Maths

        int StartingHealth{500};
        int Lost{100};

        // This will have a starting value of 400
        int RemainingHealth{StartingHealth + Lost};
        // This will increment Level's value by 1
        Level = Level + 1;

        /////////////////////////////
        // Increment and decrement operators

        Level = 5;
        Level++; // Level is now 6
        ++Level; // Level is now 7

        Level--; // Level is now 6
        --Level; // Level is now 5

        /////////////////////////////
        // Compound assignment

        Level = 5;
        Level += 3; // Level is now 8

        Level -= 3; // Level is now 5
        Level *= 3; // Level is now 15
        Level /= 5; // Level is now 3

        Level *= Level; // Level is now 9

        /////////////////////////////
        // Negative numbers

        int NegativeValue{-5};

        int Health{100};
        int HealthModifier{-10};

        Health += HealthModifier; // Health is now 90
        Health *= -1; // Health is now -90

        int Input{4};
        int Result{-Input}; // Result is -4
        Result = -(Input + 2); // Result is -4

        /////////////////////////////
        // Integer division

        std::cout << "5 / 2 = " << 5 / 2 << std::endl; // The ouput is "5 / 2 = 2"

        // IntegerLevel is 2
        int IntegerLevel{5/2};

        // FloatingLevel is 2.0
        int FloatingLevel{5/2};

        /////////////////////////////
        // Floating point numbers

        // All of these examples would log out 2.5
        std::cout << 5.0 / 2 << std::endl;
        std::cout << 5 / 2.0 << std::endl;
        std::cout << 5.0 / 2.0 << std::endl;

        5 + 1.0; // 6.0
        5.0 + 1; // 6.0

        5 - 1.0; // 4.0
        5.0 - 1; // 4.0

        5 * 2.0; // 10.0
        5.0 * 2; // 10.0

        5 / 2.0; // 2.5
        5.0 / 2; // 2.5

        float PreciseHealth{2.5};
        float PreciseHealth_2{5}; // Leads to 5.0

        /////////////////////////////
        // Floating point operations

        float MyHealth{5.0}; // MyHealth is 5.0
        MyHealth = MyHealth + 20.0; // MyHealth is now 25.0
        MyHealth++; // MyHealth is now 26.0
        MyHealth--; // MyHealth is now 25.0

        // We can freely combine floating and
        // integer numbers in the expression
        MyHealth += 25; // MyHealth is now 50.0
        MyHealth -= 10; // MyHealth is now 40.0
        MyHealth *= 2.5; // MyHealth is now 100.0
        MyHealth /= 3; // MyHealth is now 33.33333...
    }
}