#include <iostream>

using namespace std;

// Sending the variable name will only pass
// its value, not the variable itself

int Number{1};

void Increment(int x) {x++;};

/////////////////////////////////////////////
//
//              Pass by value
//
/////////////////////////////////////////////

// The same behavior can be observed with
// class methods

class Character {
    public:
        int mHealth{200};
};

void Combat(Character Player, Character Enemy) {
    
    int CombatDamages{50};
    
    cout << "Fighting at " << CombatDamages << "hp" << endl;
    Player.mHealth -= CombatDamages;
    Enemy.mHealth -= CombatDamages;
}

/////////////////////////////////////////////
//
//              Pass by reference
//
/////////////////////////////////////////////

void Increment_2(int& x) {x++;}

void Combat_2(Character& Player, Character& Enemy) {
    
    int CombatDamages{50};
    
    cout << "Fighting at " << CombatDamages << "hp" << endl;
    Player.mHealth -= CombatDamages;
    Enemy.mHealth -= CombatDamages;
}

/////////////////////////////////////////////
//
//              Output parameters
//
/////////////////////////////////////////////

int Attack(bool& wasFatal) {
    wasFatal = true;
    return 50;
}
// This works but it can be unclear what the
// function do to our variables
// Below is more friendly way to do the same:

struct AttackResult {
    int Damage;
    bool wasFatal;
};

AttackResult Attack_2() {
    return AttackResult{50, true};
}

/////////////////////////////////////////////
//
//      Reference performance and const
//
/////////////////////////////////////////////

class Character_2 {
    public:
        int mHealth{200};
};

void SomeFunction(const Character_2& Player) {
    // We can do this with a const reference:
    cout << Player.mHealth << endl;

    // But we can't do this:
    //Player.mHealth -= 50
}

/////////////////////////////////////////////
//
//           Creating references
//
/////////////////////////////////////////////

int MyNumber{5};
int& Ref{MyNumber};

/////////////////////////////////////////////
//
//          Reference restrictions
//
/////////////////////////////////////////////

// We must initialize our references
int MyNumber_2{5};
int& Ref_2{MyNumber_2};

// This will not work:
//int& Ref_3;

/////////////////////////////////////////////
//
//        Reference as class members
//
/////////////////////////////////////////////

class Weapon{
    public:
        string Name;
};

class Character_3{
    public:
        Character_3(Weapon& Sword): mSword(Sword){}
        Weapon GetWeapon(){ return mSword; }
    
    private:
        Weapon& mSword;
};

namespace References {

    void run() {

        cout << "number: " << Number << endl;
        Increment(Number);
        cout << "number: Still " << Number << endl;

        /////////////////////////////////////////

        Character Player;
        Character Enemy;
        cout << "Player: " << Player.mHealth << endl;
        cout << "Enemy: " << Enemy.mHealth << endl;
        Combat(Player, Enemy);
        cout << "Player: " << Player.mHealth << endl;
        cout << "Enemy: " << Enemy.mHealth << endl;
        // Because Player and Enemy are copies,
        // no changes are made to original objects...

        /////////////////////////////////////////

        cout << "number: " << Number << endl;
        Increment_2(Number);
        cout << "number: Now " << Number << endl;

        cout << "Player: " << Player.mHealth << endl;
        cout << "Enemy: " << Enemy.mHealth << endl;
        Combat_2(Player, Enemy);
        cout << "Player: " << Player.mHealth << endl;
        cout << "Enemy: " << Enemy.mHealth << endl;

        /////////////////////////////////////////

        bool wasFatal;
        int Damage{Attack(wasFatal)};

        cout << "Inflicted "<< Damage << " Damage";
        if (wasFatal) { cout << " (Fatal)\n"; }

        /////////////////////////////////////////

        auto [Damage_2, wasFatal_2]{Attack_2()};

        cout << "Inflicted "<< Damage_2 << " Damage";
        if (wasFatal_2) { cout << " (Fatal)\n"; }

        /////////////////////////////////////////

        Character_2 Player_2;
        SomeFunction(Player_2);

        /////////////////////////////////////////

        Ref++;
        cout << "Value: " << MyNumber << endl;

        /////////////////////////////////////////

        Weapon PlayerWeapon{"Wooden Sword"};
        Character_3 Player_3{PlayerWeapon};

        cout << Player_3.GetWeapon().Name << endl;
        PlayerWeapon.Name = "Steel Sword";
        cout << Player_3.GetWeapon().Name << endl;
    }
}