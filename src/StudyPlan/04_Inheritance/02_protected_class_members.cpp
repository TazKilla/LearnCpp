#include <iostream>

using namespace std;

class Character {
    public:
        int GetHealth() {return mHealth;}
    
    protected:
        int mHealth{100};
};

class Healer : public Character {
    public:
        void Heal(int Amount) {mHealth += Amount;}
};

namespace ProtectedClassMembers {

    void run() {
        Healer Player;
        cout << "Health: " << Player.GetHealth() << endl;

        Player.Heal(50);
        cout << "Health: " << Player.GetHealth() << endl;
    }
}