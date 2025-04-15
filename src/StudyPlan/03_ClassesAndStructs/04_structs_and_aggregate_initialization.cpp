#include <iostream>

using namespace std;

namespace StructsAndAggregateInitialization {

    struct Vector3 {
        float x;
        float y;
        float z;
    };

    void run() {
        Vector3 Position{1.9, 2.6, 0.3};
        cout << "Px=" << Position.x << ",Py=" << Position.y
             << ",Pz=" << Position.z << endl;
    }
}