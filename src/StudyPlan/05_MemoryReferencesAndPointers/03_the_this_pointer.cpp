#include <iostream>

using namespace std;

struct SomeType {
    void SomeFunction() {
        cout << this << endl;
    }
};

/////////////////////////////////////////////
//
//            Dereferencing this
//
/////////////////////////////////////////////

struct SomeType_2 {
    // Returns a pointer of type SomeType*
    SomeType_2* Pointer(){ return this; }
    // Returns a reference of type SomeType&
    SomeType_2& Reference(){ return *this; }
    // Returns a copy of type SomeType
    SomeType_2  Copy(){ return *this; }
};

/////////////////////////////////////////////
//
//   Using case 1: Identifying the caller
//
/////////////////////////////////////////////

class Character {
    public:
        Character(string Name) : mName{Name}{}

        void Attack(Character& Target){
            Target.TakeDamage(*this);
        }

        void TakeDamage(Character& Attacker){
            cout << mName << ": " << Attacker.mName << " has attacked me!" << endl;
        }

        string mName;
};

/////////////////////////////////////////////
//
//   Using case 2: Chaining function calls
//
/////////////////////////////////////////////

class Character_2 {
    public:
        Character_2& SetName(string Name){
            mName = Name;
            return *this;
        }

        Character_2& SetLevel(int Level){
            mLevel = Level;
            return *this;
        }

        Character_2& Log(){
            cout << "I am a " << mName
            << " and I am level " << mLevel
            << "!" << endl;
            return *this;
        }

    private:
        string mName;
        int mLevel;
};

/////////////////////////////////////////////
//
//   Using case 3: Overloading operators
//
/////////////////////////////////////////////

struct Vector3 {
    float x;
    float y;
    float z;

    Vector3& operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    Vector3& operator*=(int Multiplier) {
        x *= Multiplier;
        y *= Multiplier;
        z *= Multiplier;
        return *this;
    }
};

// We can do the same with free functions,
// passing the operand by reference

struct Vector3_2 {
    float x;
    float y;
    float z;
};

Vector3_2& operator++(Vector3_2& vec) {
    ++vec.x;
    ++vec.y;
    ++vec.z;
    return vec;
}

Vector3_2& operator*=(Vector3_2& vec, int mult) {
    vec.x *= mult;
    vec.y *= mult;
    vec.z *= mult;
    return vec;
}

/////////////////////////////////////////////
//
//      Prefix and postfix operators
//
/////////////////////////////////////////////

int x{5};
int y{5};

/////////////////////////////////////////////
//
//      Overloading postfix operators
//
/////////////////////////////////////////////

struct Vector3_3 {
    float x;
    float y;
    float z;

    // Prefix operator
    Vector3_3 operator++() {
        ++x;
        ++y;
        ++z;
        return *this;
    }

    // Postfix operator
    Vector3_3 operator++(int) {
        Vector3_3 temp{*this};  // Create a copy from original
        ++(*this);              // Increment original with prefix operator
        return temp;            // Return the copy
    }
};

namespace TheThisPointer{

    void run() {

        SomeType SomeObject;
        cout << &SomeObject << endl;
        SomeObject.SomeFunction();

        /////////////////////////////////////////

        Character Player{"Player One"};
        Character Monster{"Goblin"};

        Player.Attack(Monster);
        Monster.Attack(Player);

        /////////////////////////////////////////

        Character_2 Enemy;

        Enemy
            .SetName("Goblin Warrior")
            .SetLevel(10)
            .Log();
        
        /////////////////////////////////////////

        Vector3 SomeVector{1.0, 2.0, 3.0};

        (++SomeVector) *= 2;

        cout << "x = " << SomeVector.x
            << ", y = " << SomeVector.y
            << ", z = " << SomeVector.z << endl;

        Vector3_2 SomeVector_2{1.0, 2.0, 3.0};

        (++SomeVector_2) *= 2;

        cout << "x = " << SomeVector_2.x
            << ", y = " << SomeVector_2.y
            << ", z = " << SomeVector_2.z << endl;

        /////////////////////////////////////////

        cout << "x++: " << x++
            << " (x is now " << x << ")" << endl;

        cout << "++y: " << ++y
            << " (x is now " << y << ")" << endl;
    }
}