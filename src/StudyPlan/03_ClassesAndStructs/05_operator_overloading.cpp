
#include <iostream>

using namespace std;

namespace OperatorOverloading{
    
    struct Vector3 {
        float x;
        float y;
        float z;

        void print() {
            cout
                << "x=" << x
                << ", y=" << y
                << ", z=" << z
                << endl;
        }

        Vector3 operator+(Vector3& Other) {
            return Vector3{
                x + Other.x,
                y + Other.y,
                z + Other.z
            };
        }

        Vector3 operator*(int num) {
            return Vector3{
                x * num,
                y * num,
                z * num
            };
        }

        // Unary operators
        Vector3 operator-() {
            return Vector3{-x, -y, -z};
        }

        Vector3 operator-(Vector3 Other) {
            return Vector3{x - Other.x, y - Other.y, z - Other.z};
        }
    };

    void run() {
        Vector3 CurrentPosition{1.0, 2.0, 3.0};
        Vector3 Movement{4.0, 5.0, 6.0};
        Vector3 NewPosition{
            CurrentPosition + Movement
        };

        cout
            << "CurrentPosition:" << endl;
        CurrentPosition.print();

        cout
            << "Movement:" << endl;
        Movement.print();

        cout
            << "NewPosition (CurrentPosition + Movement):" << endl;
        NewPosition.print();
        
        cout
            << "Current position:" << endl;
        CurrentPosition.print();

        cout
            << "Current position * 2:" << endl;
        CurrentPosition = CurrentPosition * 2;
        CurrentPosition.print();

        cout
            << "NewPosition - CurrentPosition:" << endl;
        Vector3 NewVector = NewPosition - CurrentPosition;
        NewVector.print();

        cout
            << "CurrentPosition - NewPosition:" << endl;
        NewVector = CurrentPosition - NewPosition;
        NewVector.print();
    }
}