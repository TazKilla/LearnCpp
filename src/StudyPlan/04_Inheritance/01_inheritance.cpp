#include <iostream>

using namespace std;
    
class Actor {
    public:
        Actor(string Name = "An actor") {
            mName = Name;
        }

        void Render(){
            cout << mName << " is Rendering" << endl;
        };

    private:
        string mName;
};

class Character : public Actor {
    public:
        Character(string Name = "A character") : Actor(Name) {
            mName = Name;
        }

        void Move(){
            cout << mName << " is Moving" << endl;
        };

        void Attack(){
            cout << mName << " is Attacking" << endl;
        };

        void DropLoot(){
            cout << mName << " is Droping loot" << endl;
        };

        void Enrage(){
            cout << mName << " is Enraging" << endl;
        };
    
    private:
        string mName;

};

class Goblin : public Character {
    public:
        Goblin(string Name = "A goblin") : Character(Name) {
            mName = Name;
        }

        void Enrage(){
            cout << mName << " is Enraging" << endl;
        };
    
    private:
        string mName;
};

class Dragon : public Character {
    public:
        Dragon(string Name = "A dragon") : Character(Name) {
            mName = Name;
        }

        void Fly(){
            cout << mName << " is Flying" << endl;
        };
    
    private:
        string mName;
};

class Demon final {};

class Vampire final : public Character {};

namespace Inheritance{

    void run() {
        Goblin Bonker("Bonker");

        // Available because Bonker is a Goblin
        Bonker.Attack();

        // Available because Bonker is a Goblin
        Bonker.Render();

        Actor Rock("Rock");

        // Available because Rock is an Actor
        Rock.Render();

        // But we can't do this, because Rock is not a Goblin
        // Rock.Attack();

        Dragon Dave("Dave");

        // Dave is an actor
        Dave.Render();

        // And a Character
        Dave.Attack();

        // And a Dragon
        Dave.Fly();

        // Can't inherit from final class
        // class Warrior : public Vampire;
    }
}