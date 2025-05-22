#include <iostream>

using namespace std;

namespace Geometry{

    namespace Constants {

        float Pi { 3.14 };
    }

    float Add(float x, float y) {
        return x + y;
    }

    class Square {
        float SideLength { 5.0 };
        float Area() {
            return SideLength * SideLength;
        }
    };

    float Circumference(float Diameter) {
        // We can access Pi here as we're in
        // the same scope/namespace
        return Diameter * Constants::Pi;
    }
}

/////////////////////////////////////////////
//
//         Anonymous namespaces
//
/////////////////////////////////////////////

namespace {
    float Pi{3.14};
}

// Forward declaration of a function
// defined in 01_geometry.cpp
float GetPi();

namespace Namespaces{

    void run() {
        // Here we use the Scope Resolution Operator '::'
        // to access members of a namespace
        Geometry::Add(10, Geometry::Constants::Pi);

        /////////////////////////////////////////

        cout << "Pi in this file: " << Pi << endl;
        cout << "Pi in 01_geometry.cpp: " << GetPi() << endl;
    }
}