#include <iostream>

using namespace std;

/////////////////////////////////////////////////
//
//            Inheriting constructors
//
/////////////////////////////////////////////////

class Monster {
    public:
        Monster() = default;
        Monster(int x, int y) {
            cout << "Two integers\n";
        }
        Monster(int x, int y, int z) {
            cout << "Three integers\n";
        }
};

class Goblin : public Monster {
    public:
        // Goblin now has an (int, int, int) constructor, so
        // this will only inherit the (int, int) constructor
        using Monster::Monster;

        Goblin(int x, int y, int z) {
            cout << "I'll handle this one\n";
        }
};

/////////////////////////////////////////////////
//
//        Calling inherited constructors
//
/////////////////////////////////////////////////

class Monster_2 {
    public:
        Monster_2() {
            cout << "Default constructing Monster_2\n";
        }
};

class Goblin_2 : public Monster_2 {
    public:
        Goblin_2() {
            cout << "Default constructing Goblin_2\n";
        }
};

// The only way to call an inherited constructor is
// within a member initializer list

class Goblin_3 : public Monster_2 {
    public:
        Goblin_3() : Monster_2() {
            cout << "Default constructing Goblin_3\n";
        }
};

// We also can pass arguments to inherited constructors

class Monster_3 {
    public:
        Monster_3(int Health) : mHealth(Health) {
            cout << "Constructing Monster_3 with an int\n";
        }

        int GetHealth(){return mHealth;};
    
    private:
        int mHealth{100};
};

class Goblin_4 : public Monster_3 {
    public:
        Goblin_4() : Monster_3{150} {
            cout << "Default constructing Goblin_4\n";
        }
};

// We even have the option to send arguments to sub-class
// constructor and send it back to inherited constructor

class Goblin_5 : public Monster_3 {
    public:
        Goblin_5(int Health) : Monster_3{Health} {
            cout << "Constructing Goblin_5 with an int\n";
        }
};

// And we can mix how the arguments are used

class Goblin_6 : public Monster_3 {
    public:
        Goblin_6(int Health, int Damage) :
            Monster_3{Health}, mDamage{Damage} {
                cout << "Constructing Goblin_6 with two ints\n";
            }
        
        int GetDamage(){return mDamage;}

    private:
        int mDamage;
};

/////////////////////////////////////////////////
//
//        Updating inherited variables
//
/////////////////////////////////////////////////

class Monster_4 {
    public:
        int mHealth{100};
};

class Goblin_7 : public Monster_4 {
    public:
        Goblin_7(){ mHealth = 150; }
};

/////////////////////////////////////////////////
//
//        Shadowing inherited functions
//
/////////////////////////////////////////////////

class Monster_5 {
    public:
        void Attack(){ cout << "Monster attacking\n";}
};

class Goblin_8 : public Monster_5 {
    public:
        void Attack(){ cout << "Goblin_8 attacking\n";}
};

/////////////////////////////////////////////////
//
//        Extending inherited functions
//
/////////////////////////////////////////////////

class Monster_6 {
    public:
        void Attack(int Damage) {
            cout << "Monster_6 attacking at " << Damage << " points\n";
            cout << "Playing animation\n";
            cout << "Playing sound\n";
            cout << "Updating UI\n";
            cout << "Even more stuff\n";
        }
};

class Goblin_9 : public Monster_6 {
    public:
        void Attack(int Damage) {
            cout << "\nSome initial Goblin_9 things\n";
            Monster_6::Attack(Damage);
            cout << "\nSome final Goblin_9 things\n";
        }

        void BigAttack(int Damage) {
            if (isBigAttackReady) {
                Monster_6::Attack(Damage * 2);
                isBigAttackReady = false;
            } else {
                cout << "Big attack not ready!\n";
            }
        }
    
    private:
        bool isBigAttackReady{true};
};

namespace WorkingWithInheritedMembers{
    void run() {
        
        // Use Monster constructor
        Goblin Bonker(1, 2);

        // Use Goblin constructor
        Goblin Basher(1, 2, 3);

        /////////////////////////////////////////

        Goblin_2 Bonker_2;

        Goblin_3 Bonker_3;

        Goblin_4 Bonker_4;
        cout << "Health: " << Bonker_4.GetHealth() << endl;

        Goblin_5 Bonker_5{200};
        cout << "Health: " << Bonker_5.GetHealth() << endl;

        Goblin_6 Bonker_6{200, 15};
        cout << "Health: " << Bonker_6.GetHealth()
            << "\nDamage: " << Bonker_6.GetDamage() << endl;
        
        /////////////////////////////////////////

        Goblin_7 Bonker_7;
        cout << "Health: " << Bonker_7.mHealth << endl;

        /////////////////////////////////////////

        Goblin_8 Bonker_8;
        Bonker_8.Attack();

        /////////////////////////////////////////

        Goblin_9 Bonker_9;
        Bonker_9.Attack(12);
        Bonker_9.Attack(8);
        Bonker_9.BigAttack(12);
        Bonker_9.BigAttack(8);
    }
}