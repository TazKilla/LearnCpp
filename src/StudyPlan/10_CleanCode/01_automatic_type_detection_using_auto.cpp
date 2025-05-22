#include <iostream>

using namespace std;

float GetFloat() {
    return 3.14;
}

/////////////////////////////////////////////
//
//         auto vs dynamic typing
//
/////////////////////////////////////////////

// In JavaScript, we can do that:
// var MyVariable = 10;
// MyVariable = "Hello World!";

// Note that auto is NOT dynamic typing:
auto MyVariable{10};
// This will not work in C++:
//MyVariable = "Hello World!";
// Nor:
//auto MyVariable;

/////////////////////////////////////////////
//
//     auto with function return types
//
/////////////////////////////////////////////

auto GetDouble() {
    return 3.14;
    bool SomeCondition = true;
    if (SomeCondition) {
        // Doing this will not work because of
        // uncertain return type (can be fixed
        // by using double as return type)
        //return 9.8f;
        // But this will work:
        return static_cast<double>(9.8f);
    }
}

auto MyNumber{GetDouble()};

/////////////////////////////////////////////
//
//      auto with function arguments
//
/////////////////////////////////////////////

auto Add(auto x, auto y) {
    return x + y;
}

auto NumberA {Add(1, 2)};   // Will be of type int
auto NumberB {Add(1, 2.0)}; // Will be of type double

/////////////////////////////////////////////
//
// Qualifiers: auto pointers, auto references
//
/////////////////////////////////////////////

int x{5};

// Reference to an automaticaly deduced type
auto& ReferenceToX{x};

// Pointer to an automaticaly deduced type
auto* PointerToX{&x};

/////////////////////////////////////////////
//
//           Should we use auto?
//
/////////////////////////////////////////////

// We can use auto if it makes the code clearer:
/*
    SomeNamespace::SomeType MyObject {
        static_cast<SomeNamespace::SomeType>(Target)
    };
*/
// Can be changed, as the static cast is explicit, to:
/*
    auto MyObject {
        static_cast<SomeNamespace::SomeType>(Target)
    };
*/
// But we will prefer, in this case, to use alias:
/*
    using Party =
        std::vector<std::pair<Character*, bool>>;
    
    Party MyParty{GetParty()};
*/

// There are two main problems with auto:

// 1 - Determining the type of auto variables requires
//     tool assistance

// If our IDE can infer the type of auto variables,
// other common tools do not (GitHub, text editors, ...)

// 2 - Determining the type of auto variables requires
//     our code to be compilable

// Even if main IDEs can infer it, if for some reason
// our code is not compilable then we will lose this
// feature, and this will made issues harder to fix.

namespace AutomaticTypeDetectionUsingAuto {

    void run() {
        // This will create an int
        auto MyNumber{5};

        // Will be float
        auto MyNumber_2{GetFloat()};
    }
}