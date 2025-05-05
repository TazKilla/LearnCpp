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
    }
}