#include <iostream>

using namespace std;

namespace AbstractionAndClasses {

    class Monster {
        public:
            int Health{100};
    };

    void run() {
        Monster Bonker;
        Monster Basher;
        cout << "Bonker Health: " << Bonker.Health << endl;
        cout << "Basher Health: " << Basher.Health << endl;

        Bonker.Health = 50;
        cout << "Bonker Health: " << Bonker.Health << endl;
        cout << "Basher Health: " << Basher.Health << endl;
    }
}