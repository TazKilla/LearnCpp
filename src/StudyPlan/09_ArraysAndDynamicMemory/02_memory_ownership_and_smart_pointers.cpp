#include <iostream>

using namespace std;

/////////////////////////////////////////////
//
//    Dynamic memory and memory ownership
//
/////////////////////////////////////////////

// To mitigate issues that appears with
// dynamic memory (memory leaks, dangling pointers, ...)
// we can implement the "memory ownership" design pattern.

/////////////////////////////////////////////
//
//               Smart pointers
//
/////////////////////////////////////////////

// The std::unique_ptr points to an object in memory.
// This one should be the ONLY unique pointers that
// points to this object.

/////////////////////////////////////////////
//
//             std::make_unique
//
/////////////////////////////////////////////

#include <memory>
// cf run()

/////////////////////////////////////////////
//
//       Dereferencing unique pointers
//
/////////////////////////////////////////////

class Character {
    public:
        string mName;
        Character(string Name = "Frodo") :
            mName{Name} {
                cout << "Creating " << mName << endl;
            }
        
        ~Character() {
            cout << "Deleting " << mName << endl;
        }
};

// cf run_2()

/////////////////////////////////////////////
//
//         Copying unique pointers
//
/////////////////////////////////////////////

void SomeFunction(int* Num) {
    // ...
}

// cf run_3()

/////////////////////////////////////////////
//
//                 std::move()
//
/////////////////////////////////////////////

// If we need to transfer ownership, we can use
// std::move()

void TakeOwnership(unique_ptr<int> Num) {
    cout << "TakeOwnership function now owns the pointer." << endl;
    cout << "Value: " << *Num << endl;
}

// cf run_4()

namespace MemoryOwnershipAndSmartPointers {

    void run() {
        // The real type of the pointer is std::unique_ptr<int>
        auto Pointer { make_unique<int>(42)};
    }

    void run_2() {
        auto FrodoPointer{
            make_unique<Character>("Frodo")
        };
        cout << "Logging " << (*FrodoPointer).mName << endl << endl;

        auto GandalfPointer{
            make_unique<Character>("Gandalf")
        };
        cout << "Logging " << (*GandalfPointer).mName << endl << endl;
    }

    void run_3() {

        auto Ptr1{make_unique<int>(42)};
        // We can't copy the unique pointer explicitely
        //auto Ptr2{Ptr1};

        auto Ptr(make_unique<int>(42));
        // And we can't either copy it implicitly by
        // sending it as an argument (by value)
        //SomeFunction(Ptr);
        // To send it to a function, we can use the get() function
        SomeFunction(Ptr.get());
    }

    void run_4() {
        auto Number{make_unique<int>(42)};
        cout << "Main function owns the pointer." << endl;

        TakeOwnership(move(Number));

        // Number is now in a "moved-from" state and should be reassigned
        // or forgeted
        if (Number == nullptr) {
            cout << "Number no longer owns any object." << endl;
        }
    }
}