#include <iostream>

using namespace std;

/////////////////////////////////////////////
//
//          Overloading functions
//
/////////////////////////////////////////////

struct Rectangle {
    float Width;
    float Height;
};

struct Circle {
    float Radius;
};

float CalculateArea(const Rectangle& R) {
    return R.Width * R.Height;
}

float CalculateArea(const Circle& C) {
    return 3.14 * C.Radius * C.Radius;
}

/////////////////////////////////////////////
//
//      Overloading member functions
//
/////////////////////////////////////////////

class Weapon{};

class Shield{};

class Character {
    public:
        void Equip(Weapon* Weapon) {
            mWeapon = Weapon;
        }

        void Equip(Shield* Shield) {
            mShield = Shield;
        }
    
    private:
        Weapon* mWeapon{nullptr};
        Shield* mShield{nullptr};
};

/////////////////////////////////////////////
//
//         Ambiguous function calls
//
/////////////////////////////////////////////

void Func(int Arg){};
void Func(float Arg){};

namespace FunctionOverloading{

    void run() {
        Circle MyCircle{2};
        Rectangle MyRectangle{3, 4};

        cout << "Circle area: "
            << CalculateArea(MyCircle) << endl;

        cout << "Rectangle area: "
            << CalculateArea(MyRectangle) << endl;

        /////////////////////////////////////////

        Character Player;
        Weapon WoodenSword;

        Player.Equip(&WoodenSword);

        Shield WoodenShield;

        Player.Equip(&WoodenShield);

        /////////////////////////////////////////

        // Ambiguous call
        //Func(1.5);

        // Call Func(int)
        Func(1);

        // Call Func(float)
        Func(1.5f);
    }
}