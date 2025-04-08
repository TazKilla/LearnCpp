#include <iostream>

namespace FunctionArgumentsAndParameters {
    /////////////////////////////
    // Function arguments

    int Health{200};

    void TakeDamage(int Damage, bool isMagical = false) {
        std::cout << "Inflicting 50 damage - ";
        Health -= isMagical ? Damage * 2 : Damage;
        std::cout << "Health: " << Health << std::endl;
    }

    int CalculateDamage(int Category) {
        
        int result = 0;
        switch (Category) {
            case 0:
                result = 10;
                break;

            case 1:
                result = 20;
                break;

            case 2:
                result = 30;
                break;

            case 3:
                result = 40;
                break;

            case 4:
                result = 50;
                break;
        };
        return result;
    }

    void run() {
        
        bool isWizard{true};

        TakeDamage(CalculateDamage(0));
        TakeDamage(CalculateDamage(3), isWizard);
        TakeDamage(CalculateDamage(4));
    }

}