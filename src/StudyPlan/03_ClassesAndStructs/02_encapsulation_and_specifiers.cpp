#include <iostream>

using namespace std;

namespace EncapsulationAndSpecifiers {
    class Monster {
        public:
            int GetHealth() {return Health;}

            void SetHealth(int IncomingHealth) {
                if (IncomingHealth < 0) {
                    Health = 0;
                } else {
                    Health = IncomingHealth;
                }
            }

            void TakeDamage(int Damage) {
                Health -= Damage;
                if (Health < 0) {Health = 0;}
            }
        
        private:
            int Health{150};
    };

    void run() {
        Monster Goblin;
        cout << "Health: " << Goblin.GetHealth() << endl;
        Goblin.SetHealth(-50);
        cout << "Health: " << Goblin.GetHealth() << endl;
    }
}