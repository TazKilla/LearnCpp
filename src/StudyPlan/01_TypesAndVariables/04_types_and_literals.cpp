
#include <iostream>

namespace TypesAndLiterals {
    void run() {
        /////////////////////////////
        // Integer width

        int8_t Level{50}; // Can store from -128 to 127, on 8 bits;

        int8_t SmallNumber{100}; // Can store 256 values
        int16_t MediumNumber{10'000}; // Can store 65'536 values
        int32_t LargeNumber{1'000'000'000}; // Can store over 4 billions...
        int64_t HugeNumber{1'000'000'000'000'000'000}; // ...

        /////////////////////////////
        // Fixed width integers

        short SmallNumber_2{100};
        int MediumNumber_2{10'000};
        long LargeNumber_2{1'000'000'000};

        // Good practice is to use int everywhere, and, when needed,
        // appropriate fixed-width type

        /////////////////////////////
        // Overflows

        int Number{2'000'000'000};
        Number += 1'000'000'000;
        std::cout << Number << std::endl;

        /////////////////////////////
        // Signed and unsigned integers

        // These are fine
        int8_t NegativeNumber{-100};
        int8_t PositiveNumber{100};

        // Error: this is out of range
        //int8_t LargeNumber_3{200};

        // Error: this it out of range
        //uint8_t NegativeNumber_2{-100};

        // These are fine
        uint8_t PositiveNumber_2{100};
        uint8_t LargerNumber{200};

        /////////////////////////////
        // Problems with unsigned integers

        unsigned int Health{0};
        Health -= 1;
        std::cout << Health << std::endl;

        int Signed{-1};
        unsigned int Unsigned{1};
        if (Signed > Unsigned) {
            std::cout << Signed << " is greater than "
            << Unsigned << " ???" << std::endl;
        }

        /////////////////////////////
        // Floating point width

        float A{3.14};
        double B{9.8};

        // Cause cout to show more decimal places
        // when outputting floating point numbers
        std::cout.precision(16);

        A = 1.1111111111111111;
        std::cout << "Float precision: "
            << A + A << std::endl;

        B = 1.1111111111111111;
        std::cout << "Double precision: "
            << B + B << std::endl;
    }
}