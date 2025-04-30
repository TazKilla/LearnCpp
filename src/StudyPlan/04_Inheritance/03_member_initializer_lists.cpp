#include <iostream>

using namespace std;

class Character {
    public:
        Character(int Health, int Level) : 
            mHealth{Health},
            mLevel{Level} {
            cout << "Creating character with "
                << mHealth << " HP and level "
                << mLevel << endl;
        }
    
    private:
        int mHealth;
        int mLevel;
};

namespace MemberInitializerLists{

    void run() {
        Character SmallCharacter{150, 5};
        Character BigCharacter{300, 15};
    }
}