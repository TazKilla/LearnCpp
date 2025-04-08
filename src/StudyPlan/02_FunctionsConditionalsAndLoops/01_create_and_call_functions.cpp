#include <iostream>

namespace CreateAndCallFunctions {
    /////////////////////////////
    // Creating functions

    int Health{150};
    bool isDead{false};

    void TakeDamage() {
        std::cout << "Taking Damage" << std::endl;
        Health -= 150;
        isDead = true;
    }

    void run() {
        TakeDamage();
    }
}