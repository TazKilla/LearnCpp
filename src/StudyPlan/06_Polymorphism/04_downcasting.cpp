#include <iostream>

using namespace std;

class Character {
    public:
        Character(string Name) : mName{Name} {}
        string GetName(){ return mName; }
    
    private:
        string mName;
};

class Goblin : public Character {
    public:
        Goblin(string Name) : Character{Name} {}

        void Enrage(){
            cout << "Getting angry!" << endl;
            Damage += 5;
        }

        void CalmDown(){
            cout << "Getting quieter." << endl;
            Damage -= 5;
        }
    
    private:
        int Damage{10};
};

void Act(Character* Enemy) {
    cout << Enemy->GetName() << " acting" << endl;
}

/////////////////////////////////////////////
//
//      Why do we need downcasting?
//
/////////////////////////////////////////////

// In the Act() function, we can't call the Enrage()
// function from our Goblin

/////////////////////////////////////////////
//
//      Downcasting using static_cast
//
/////////////////////////////////////////////

// To be able to call Enrage() from the Act() function,
// we can use static_cast

void Act_2(Character* Enemy) {
    cout << Enemy->GetName() << " acting" << endl;
    static_cast<Goblin*>(Enemy)->Enrage();
}

/////////////////////////////////////////////
//
//      Downcasting using dynamic_cast
//
/////////////////////////////////////////////

class Character_2 {
    public:
        virtual ~Character_2() = default;
};

class Goblin_2 : public Character_2 {};

void Handle(Character_2* Object) {
    Goblin_2* GoblinPointer{
        dynamic_cast<Goblin_2*>(Object)
    };

    if (GoblinPointer) {
        cout << "That was a Goblin" << endl;
    } else {
        cout << "That wasn't a Goblin" << endl;
    }
};

/////////////////////////////////////////////
//
//            A practical example
//
/////////////////////////////////////////////

class Character_3 {
    public:
        Character_3(string Name) : mName{Name}{}
        string GetName() { return mName; }

        void TakeDamage(int Damage) {
            cout << mName << " taking damages" << endl;
            mHealth -= Damage;
        }

        virtual void Act(Character_3* Target) {
            Target->TakeDamage(50);
        }
    
    protected:
        string mName;
        int mHealth{150};
};

class Vampire : public Character_3 {
    public:
        Vampire(string Name) : Character_3{Name}{}

        void Stake() {
            cout << mName << " getting staked" << endl;
            mHealth = 0;
        }
};

class VampireHunter : public Character_3 {
    public:
        VampireHunter(string Name) : Character_3{Name} {}

        void Act(Character_3* Target) override {
            Vampire* VampirePtr{
                dynamic_cast<Vampire*>(Target)
            };

            if (VampirePtr) {
                VampirePtr->Stake();
            } else {
                Character_3::Act(Target);
            }
        }
};

void Battle(Character_3* A, Character_3* B) {
    B->Act(A);
    A->Act(B);
}

namespace Downcasting {

    void run() {
        Goblin Bonker{"Bonker"};
        Act(&Bonker);
        Act_2(&Bonker);

        /////////////////////////////////////////

        Goblin_2 Enemy;
        Handle(&Enemy);

        Character_2 Player;
        Handle(&Player);

        /////////////////////////////////////////

        Character_3 Player_2("Player");
        Character_3 EnemyGoblin("Goblin");

        Battle(&Player_2, &EnemyGoblin);
        cout << endl;

        Character_3 EnemyVampire("Vampire");

        Battle(&Player_2, &EnemyVampire);
        cout << endl;
        
        /////////////////////////////////////////

        VampireHunter Player_3("Player");
        Character_3 EnemyGoblin_2("Goblin");

        Battle(&Player_3, &EnemyGoblin_2);
        cout << endl;

        Vampire EnemyVampire_2{"Vampire"};
        
        Battle(&Player_3, &EnemyVampire_2);
        cout << endl;
    }
}