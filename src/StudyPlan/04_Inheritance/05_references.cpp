#include <iostream>

using namespace std;

namespace References {

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
    }
}