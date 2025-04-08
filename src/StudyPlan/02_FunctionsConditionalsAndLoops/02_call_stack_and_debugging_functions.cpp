#include <iostream>

namespace CallStackAndDebuggingFunctions {
    /////////////////////////////
    // The Call stack and the Debugger

    int Health{150};

    int WeaponIDs[]{15, 10, 35, 4, 50, 11, 64};

    int GetArmor(int targetLevel) {
        std::cout << "    - GetArmor function starting" << std::endl;
        int armor = 0;
        switch (targetLevel) {
            case 1:
            case 2:
            case 3:
                armor = 2;
                break;
            case 4:
            case 5:
            case 6:
                armor = 5;
                break;
            case 7:
            case 8:
            case 9:
                armor = 10;
                break;
            
            default:
                break;
        }
        std::cout << "    - GetArmor function complete" << std::endl;
        return armor;
    }

    int GetDamage(int weaponID) {
        int damage = 0;
        std::cout << "    - GetDamage function starting" << std::endl;
        if(weaponID < 0 || weaponID > sizeof(WeaponIDs)) {
            std::cout << "Unknown weapon ID: " << weaponID << std::endl;
            damage = -1;
        }
        else damage = WeaponIDs[weaponID];
        std::cout << "    - GetDamage function complete" << std::endl;
        return damage;
    }

    void TakeDamage(int weaponID, int targetLevel) {
        std::cout << " - Takedamage function starting" << std::endl;
        Health -= GetDamage(weaponID) - GetArmor(targetLevel);
        std::cout << " - Takedamage function complete" << std::endl;
    }

    void run() {
        std::cout << "Main function starting" << std::endl;
        TakeDamage(2, 1);
        std::cout << "Character's Health: " << Health << std::endl;
        std::cout << "Back in main function" << std::endl;
        TakeDamage(4, 7);
        std::cout << "Character's Health: " << Health << std::endl;
        std::cout << "Main function complete" << std::endl;
    }
}