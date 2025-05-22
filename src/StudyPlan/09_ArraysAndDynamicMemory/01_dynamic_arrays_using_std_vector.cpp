#include <iostream>
#include <vector>

using namespace std;

/////////////////////////////////////////////
//
//         Accessing array items
//
/////////////////////////////////////////////

vector MyVector {1, 2, 3, 4, 5};

int FirstElement{MyVector[0]};
int SecondElement{MyVector[1]};
int ThirdElement{MyVector[2]};
int LastElement{MyVector[4]};

int CalculateIndex() { return 1 + 1; };

/////////////////////////////////////////////
//
//                Array size
//
/////////////////////////////////////////////

// cf run_2()

/////////////////////////////////////////////
//
//        Adding and removing items
//
/////////////////////////////////////////////

class Character {
    public:
        Character(const string& Name) : mName{Name} {}
        
        string mName;
};

// cf run_3()

/////////////////////////////////////////////
//
//        Modifying array items
//
/////////////////////////////////////////////

// cf run_4()

class Character_2 {
    public:
        Character_2(string Name) : mName{Name} {}
        string GetName() { return mName; }
        void SetName(string Name) {
            mName = Name;
        }

    private:
        string mName;
};

/////////////////////////////////////////////
//
//     Storing complex types in arrays
//
/////////////////////////////////////////////

class Character_3 {
    public:
        Character_3(string Name) : mName{Name} {}

    private:
        string mName;
};

Character_3 Player_2{"Riri"};
Character_3 Player_3{"Fifi"};
Character_3 Player_4{"Loulou"};

const Character_3 Player_5{"Donald"};
const Character_3 Player_6{"Daisy"};
const Character_3 Player_7{"Gontran"};

// A collection of characters
vector<Character_3> Players{Player_2, Player_3, Player_4};

// A collection of character pointers
vector<Character_3*> Player_ptrs{&Player_2, &Player_3, &Player_4};

// A collection of const character references
//vector<const Character_3&> Player_const_refs{Player_5, Player_6, Player_7};

// Alias for long types
using Grid = vector<vector<int>>;

Grid MyGrid {{
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
}};

// cf run_5()

/////////////////////////////////////////////
//
//     Passing arrays to functions
//
/////////////////////////////////////////////

void LogTopLeft(Grid GridToLog) {
    cout << "Top left: " << GridToLog[0][0] << endl;
}

// cf run_6()

// To save resources, we can pass arrays by reference
void LogBottomRight(const Grid& GridToLog) {
    cout << "Bottom right: " << GridToLog.back().back() << endl;
}

void SetBottomRight(Grid& GridToLog, int Value) {
    GridToLog.back().back() = Value;
}

// cf run_7()

// It also works with pointers instead of references
void LogBottomRight_2(const Grid* GridToLog) {
    cout << "Bottom right: " << (*GridToLog).back().back() << endl;
}

void SetBottomRight_2(Grid* GridToLog, int Value) {
    (*GridToLog).back().back() = Value;
}

// cf run_8()

/////////////////////////////////////////////
//
//       Iteration using a for loop
//
/////////////////////////////////////////////

// cf run_9()

/////////////////////////////////////////////
//
//             The size_t type
//
/////////////////////////////////////////////

// cf run_10()

/////////////////////////////////////////////
//
//          Range-based for loop
//
/////////////////////////////////////////////

// cf run_11()

/////////////////////////////////////////////
//
//            Memory management
//
/////////////////////////////////////////////

// Comparing array size() end capacity()

// cf run_12()

// Proactively reserving capacity

// cf run_13()

namespace DynamicArraysUsingStdVectors {

    void run() {

        vector MyVector_2{
            "First", "Second", "Third"
        };

        // Log out the elementa at index 0
        cout << MyVector_2[3 - 3] << endl;

        // Log out the elementa at index 1
        int Index{1};
        cout << MyVector_2[Index] << endl;

        // Log out the elementa at index 2
        cout << MyVector_2[CalculateIndex()] << endl;
    }

    void run_2() {

        vector MyVector_3{
            "First", "Second", "Third"
        };

        cout << "Size: " << MyVector_3.size() << endl;

        cout << "Last element: " << MyVector_3[MyVector_3.size() - 1] << endl;

        // Equivalently:
        cout << "Last element: " << MyVector_3.back() << endl;
    }

    void run_3() {

        Character Legolas{"Legolas"};
        vector<Character> MyVector_4;
        MyVector_4.push_back(Legolas);

        cout << "First character: " << MyVector_4[0].mName << endl;

        /////////////////////////////////////////

        MyVector_4.emplace_back("Aragorn");
        MyVector_4.emplace_back("Gandalf");

        cout << "Second character: " << MyVector_4[1].mName << endl;
        MyVector_4.erase(MyVector_4.begin() + 1);
        cout << "Second character is now: " << MyVector_4[1].mName << endl;
    }

    void run_4() {

        vector MyVector_5{1, 2, 3};

        cout << "Second number: " << MyVector_5[1] << endl;
        MyVector_5[1] = 42;
        cout << "New second number: " << MyVector_5[1] << endl;

        /////////////////////////////////////////

        vector<Character_2> MyVector_6;
        MyVector_6.emplace_back("Roderick");

        cout << "First character: " << MyVector_6[0].GetName() << endl;
        MyVector_6[0].SetName("Anna");
        cout << "New first character: " << MyVector_6[0].GetName() << endl;

    }

    void run_5() {

        cout << "Top left: " << MyGrid[0][0] << endl;

        cout << "Bottom right: " << MyGrid[2][2] << endl;
        // Alternatively: MyGrid.back().back()
    }

    void run_6() {

        Grid MyGrid {{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }};

        LogTopLeft(MyGrid);
    }

    void run_7() {

        Grid MyGrid {{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }};

        LogBottomRight(MyGrid);
        SetBottomRight(MyGrid, 42);
        LogBottomRight(MyGrid);
    }

    void run_8() {

        Grid MyGrid {{
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
        }};

        LogBottomRight_2(&MyGrid);
        SetBottomRight_2(&MyGrid, 42);
        LogBottomRight_2(&MyGrid);
    }

    void run_9() {
        vector MyVector{1, 2, 3};

        for (int i{0}; i < MyVector.size(); ++i) {
            cout << MyVector[i] << ", ";
        }
        cout << endl;
    }

    void run_10() {
        // Because indices can be larger that regular int type,
        // it's prefered to use size_t for array size and indices
        vector MyVector{1, 2, 3};

        for (size_t i{0}; i < MyVector.size(); ++i) {
            cout << MyVector[i] << ", ";
        }
        cout << endl;
    }

    void run_11() {
        // If we just want to iterate over every items in an array,
        // we can use this syntax
        vector MyVector{1, 2, 3};

        for (int Number : MyVector) {
            cout << Number << ", ";
        }
        cout << endl;

        // If the type used is expensive to copy, we can send
        // parameters by reference
        for (int& Number : MyVector) {
             cout << Number << ", ";
        }
        cout << endl;

        // We can also send it as const if the loop body doesn't
        // modify the reference
        for (const int& Number : MyVector) {
             cout << Number << ", ";
        }
        cout << endl;
    }

    void run_12() {
        vector MyVector{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

        cout << "Capacity: " << MyVector.size()
            << "/" << MyVector.capacity() << endl;
        vector<int>* VectorPtr = &MyVector;
        cout << "The array is full, located at " << VectorPtr << ", it may be moved if it grows" << endl;
        MyVector.emplace_back(6);

        cout << "Capacity: " << MyVector.size()
            << "/" << MyVector.capacity() << endl;
        cout << "The array has grown, and is " << (&MyVector == VectorPtr ? "still " : "now ") << "located at " << &MyVector << endl;
    }

    void run_13() {
        vector MyVector{1, 2, 3, 4, 5};
        // If we know how big can be our array,
        // we should reserve its place
        MyVector.reserve(100);

        cout << "Capacity: " << MyVector.size()
            << "/" << MyVector.capacity() << endl;
    }
}