#include <iostream>

using namespace std;

/////////////////////////////////////////////
//
//           Runtime polymorphism
//
/////////////////////////////////////////////
//
//            Step 1: Inheritance
//
/////////////////////////////////////////////

class Character {
    public:
        virtual void Act(Character* Target) {
            cout << "Character acting" << endl;
        }

        bool GetIsAlive(){ return IsAlive; }
    
    private:
        bool IsAlive{true};
};

//class Goblin : public Character {};

//class Dragon : public Character {};

/////////////////////////////////////////////
//
//      Step 2: References and pointers
//
/////////////////////////////////////////////

void Battle(Character* A, Character* B) {
    while (A->GetIsAlive() && B->GetIsAlive()) {
        A->Act(B);
        B->Act(A);
    }
}

/////////////////////////////////////////////
//
//        Step 3: Virtual functions
//
/////////////////////////////////////////////

class Goblin : public Character {
    public:
        void Act(Character* Target) override {
            cout << "Goblin acting" << endl;
        }
};

class Dragon : public Character {
    public:
        void Act(Character* Target) override {
            cout << "Dragon acting" << endl;
        }
};

class FireDragon : public Dragon {};
class FrostDragon : public Dragon {};
class StormDragon : public Dragon {};

namespace VirtualFunctionsAndOverrides {

    void run() {

        Goblin A;
        Dragon B;
        Battle(&A, &B);
    }
}