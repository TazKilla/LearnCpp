#include <iostream>
#include <string>

using namespace std;

namespace ConstructorsAndDestructors {

    class Monster {
        public:
            // Custom constructor
            Monster(string Name, int Health = 150) {
                mName = Name;
                mHealth = Health;
                cout << mName << " Ready for Battle!" << endl;
                cout << "Health: " << mHealth << endl;
                cout << "Monster created" << endl;
            }

            // Destructor
            ~Monster() {
                cout << "Monster destroyed" << endl;
            }
        
        private:
            string mName;
            int mHealth;
    };

    void run() {
        Monster Bonker("Bonker");
        Monster Basher("Basher", 250);
    }
}