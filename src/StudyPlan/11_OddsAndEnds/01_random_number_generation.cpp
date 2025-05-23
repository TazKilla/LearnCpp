#include <iostream>

#include "01_random.h"

using namespace std;

/////////////////////////////////////////////
//
//    Seeding a random number generator
//
/////////////////////////////////////////////

// cf Random.h file and run()

/////////////////////////////////////////////
//
//    Uniform and normal distributions
//
/////////////////////////////////////////////

/*
  30
F                          #
r                          #
e 20                       #
q                      #   #   #
u                      #   #   #
e 10  *   *   *   *#  *#  *#  *#  *#  *   *   *
n     *   *   *#  *#  *#  *#  *#  *#  *   *   *
c     *#  *#  *#  *#  *#  *#  *#  *#  *#  *#  *#
y  O  15  16  17  18  19  20  21  22  23  24  25

**** Uniform distribution
#### Normal distribution
*/

/////////////////////////////////////////////
//
//             Random booleans
//
/////////////////////////////////////////////

// cf Bool in Random.h and run_2()

/////////////////////////////////////////////
//
//   Controlling and reproducing randomness
//
/////////////////////////////////////////////

// cf PrintSeed in Random.h and run_3()

class Character {
    // Each attack can do between 15 and 25 damage
    int MinDamage{15};
    int MaxDamage{15};

    // Character has 20% chance to avoid damage
    float DodgeChance{0.2};

    int Health{100};

    void TakeDamage(int Damage) {
        if (Random::Bool(DodgeChance)) {
            return; // Dodged! No damage
        }
        Health -= Damage;
    }

    void Act(Character* Target) {
        Target->TakeDamage(
            Random::Int(MinDamage, MaxDamage)
        );
    }
};

namespace RandomNumberGeneration {

    void run() {
        cout << Random::Int(1, 10) << ", "
        << Random::Int(1, 10) << ", "
        << Random::Int(1, 10) << endl;
    }

    void run_2() {
        for (int i{0}; i < 10; i++) {
            if (Random::Bool(0.2)) {
                cout << "Dodge";
            } else {
                cout << "Hit";
            }
            if (i < 9) {
                cout << ", ";
            } else {
                cout << endl;
            }
        }
    }

    void run_3() {
        Random::PrintSeed();
        cout << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << endl;

        // We can still get random numbers
        Random::PrintSeed();
        cout << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << endl;

        // But now we can create reproducible results:
        Random::Reseed(141102604);
        Random::PrintSeed();
        cout << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << endl;

        cout << "Let's go again - ";
        Random::Reseed(141102604);
        Random::PrintSeed();
        cout << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << ", "
             << Random::Int(1, 100) << endl;
    }
}