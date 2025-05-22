#include <iostream>

using namespace std;

enum class Faction {
    Goblin,
    Undead,
    Troll,
    Dragon
};

Faction EnemyType{Faction::Dragon};

bool isTroll(Faction SelectedFaction) {
    return SelectedFaction == Faction::Troll;
}

class Vampire {
    public:
        Faction GetFaction() { return mFaction; }
    private:
        Faction mFaction { Faction::Undead };
};

Vampire Enemy;
Faction EnemyFaction { Enemy.GetFaction() };

namespace Enums {

    void run() {

    }
}