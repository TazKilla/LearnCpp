#include <iostream>

using namespace std;

/////////////////////////////////////////////
//
//      Static casting with static_cast
//
/////////////////////////////////////////////

float SomeFloat{10.f};
bool SomeBoolean{true};

double SomeFunction(){
    return 1.0;
}

int Add(int x, int y){
    return x + y;
}

// static_cast also works with other
// types, even custom ones
// static_cast<float>(5.0);
// static_cast<Vector3>(142);
// static_cast<Monster>(5);

/////////////////////////////////////////////
//
//              C-Style casting
//
/////////////////////////////////////////////

// Using the three examples above,
// C-Style cast looks like
// (float)(5.0);
// (Vector3)(142);
// (Monster)(5);

// Its highly recommanded to use named casts
// available with C++, to avoid ambiguous
// instructions, like
// int Num{(int)("Hi")};

namespace StaticCasting {

    void run() {

        // To convert 5 to a float
        static_cast<float>(5);

        // To convert 5.0 to an int
        static_cast<int>(5.0);

        // More generally, to convert SomeExpression into SomeType
        // static_cast<SomeType>(SomeExpression);

        // More examples
        static_cast<int>(20.0f);
        static_cast<int>(25.0);
        static_cast<int>(25.0 / 5);

        static_cast<int>(SomeFloat);

        static_cast<int>(SomeBoolean ? 20 : 50.0);

        static_cast<int>(SomeFunction());

        // What we got from static_cast<int> is an integer
        // and can be used like any other int

        // Saving the result to a variable
        int MyInt1 { static_cast<int>(20.f) };
        int MyInt2 { static_cast<int>(25.0) / 5 };

        // Passing the result to a function
        Add(
            static_cast<int>(1.f),
            static_cast<int>(2.0)
        );
    }
}