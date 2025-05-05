#include <iostream>

using namespace std;

/////////////////////////////////////////////
//
//        The address of operator: &
//
/////////////////////////////////////////////

int x{1};

/////////////////////////////////////////////
//
//                 Pointers
//
/////////////////////////////////////////////

// Create a pointer to an int
int x_2{1};
int* MyPointer{&x};

// And we can pass it to a function
void HandlePointer(int* Pointer) {
    // ...
}

/////////////////////////////////////////////
//
//          Dereferencing pointers
//
/////////////////////////////////////////////

void HandlePointers_2(int* Pointer){
    int Dereferenced{*Pointer};
    cout << "Dereferenced: " << Dereferenced << endl;
}

// A pointer to an int
int* PointerToInt{&x_2};

// Dereferencing a pointer, returning the
// underlying value - an int in this case
int x_4 { *PointerToInt };

/////////////////////////////////////////////
//
//           Pointers vs references
//
/////////////////////////////////////////////

// Using reference
void Increment(int& Number) {
    Number++;
}

void Increment_2(int* Number) {
    (*Number)++;
}

/////////////////////////////////////////////
//
//           The arrow operator ->
//
/////////////////////////////////////////////

class Monster{
    public:
        void TakeDamage(int Damage) {
            mHealth -= Damage;
        }

    private:
        int mHealth{150};
};

void Combat(Monster* Enemy) {
    // Here we need to dereference the pointer
    // in order to use the member access operator '.'
    (*Enemy).TakeDamage(50);
}

void Combat_2(Monster* Enemy) {
    // But we can use the arrow operator,
    // acting like both dereferencing
    // and member access operators
    Enemy->TakeDamage(50);
}

/////////////////////////////////////////////
//
//             Null pointers
//
/////////////////////////////////////////////

class Weapon {
    public:
        string mName{"Iron Sword"};
};

class Character {
    public:
        Weapon* mWeapon{nullptr};
};

// Here is a slightly more complex example: 
class Character_2 {
    public:
        Character_2(string Name): mName{Name}{};

        void SetEnemy(Character_2* Enemy){
            mEnemy = Enemy;
        }

        void LogEnemy(){
            if (mEnemy) {
                cout << "Enemy: " << mEnemy->mName << endl;
            } else {
                cout << "I don't have an enemy" << endl;
            }
        }

        string mName;
        Character_2* mEnemy{nullptr};
};

namespace Pointers{
    
    void run() {
        // Log out the location of x in memory
        cout << &x << endl;

        // Create a reference to x
        int& ReferenceToX{x};

        // Find out where x is stored in memory
        &x;

        /////////////////////////////////////////

        int x_3{42};
        HandlePointer(&x);

        /////////////////////////////////////////

        HandlePointers_2(&x_3);

        /////////////////////////////////////////

        Increment(x_3);
        Increment_2(&x_3);

        /////////////////////////////////////////

        Character Player;
        Weapon Sword;
        if(!Player.mWeapon) {
            cout << "I am unarmed." << endl;
        }
        Player.mWeapon = &Sword;
        if(Player.mWeapon) {
            cout << "But not anymore! Behold my "
            << Player.mWeapon->mName << endl;
        }

        /////////////////////////////////////////

        Character_2 Player_2{"Anna"};
        Player_2.LogEnemy();

        Character_2 Enemy{"Goblin Warrior"};
        Player_2.SetEnemy(&Enemy);
        Player_2.LogEnemy();

        Character_2 AnotherEnemy{"Vampire Bat"};
        Player_2.SetEnemy(&AnotherEnemy);
        Player_2.LogEnemy();
    }
}