#include <iostream>

namespace Booleans {
    void run() {
        /////////////////////////////
        // Creating booleans by comparing numbers

        int Level{10};

        // Level is 10, so isLevel10 will be true
        bool isLevel10{Level == 10};

        // This will be false
        bool isLevel15{Level == 15};

        Level = 20;
        int TargetLevel{20};

        // This will be true
        bool isTargetLevel{Level == TargetLevel};

        Level = 10;
        bool isNotLevel10{Level != 10}; // False
        bool isNotLevel15{Level != 15}; // True

        bool isAboveLevel10{Level > 10}; // False
        bool isAtLeastLevel10{Level >= 10}; // True

        bool isBelowLevel10{Level < 10}; // False
        bool isLevel10OrBelow{Level <= 10}; // True

        float Health{100.0};
        bool isHealthy{Health > 50.0};
        bool isMaxHealth{Health >= 100};

        float MaxHealth{150.0};
        bool isAbove50Percent{Health / MaxHealth > 0.5};

        /////////////////////////////
        // ! operator

        bool isAlive{true};
        bool isDead{!isAlive};

        /////////////////////////////
        // Combining booleans

        Level = 10;
        bool isAlive = true;

        // This will be true
        bool isReady{Level == 10 && isAlive};

        // This will be true
        isReady = Level == 10 || Level == 20;

        // true only if ALL conditions are true
        isReady && isAlive && isAbove50Percent;

        // true if ANY condition is true
        isReady || isAlive || isAbove50Percent;

        Level = 10;
        isDead = true;

        // This will be true because Level == 10 is true
        bool isMilestoneLevel{
            Level == 10 || Level == 20 || Level == 30
        };

        // This will be false because !isDead is false
        bool canStartQuest{
            Level >= 10 && Level <= 20 && !isDead
        };

        Level = 10;
        isAlive = true;

        bool isLevel10Or20AndAlive{
            (Level == 10 || Level == 20) && isAlive
        };
    }
}