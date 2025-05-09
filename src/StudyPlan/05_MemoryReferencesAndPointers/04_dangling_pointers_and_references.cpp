#include <iostream>

using namespace std;

// Regarding memory management, we may face some
// issues when working with pointers and references

int* GetNumber() {
    int Number{1};
    return &Number;
}

/////////////////////////////////////////////
//
//               Stack memory
//
/////////////////////////////////////////////

// We can see what appends above by using a custom
// type with destructor

struct SomeType {
    int Value{1};
    ~SomeType(){ cout << "Destroying" << endl; }
};

SomeType* GetObject(){
    SomeType SomeObject;
    return &SomeObject;
}

namespace DanglingPointersAndReferences {

    void run() {

        int* Result{GetNumber()};
        // The instruction below leads to SegFault
        //cout << "Result: " << *Result << endl;

        /////////////////////////////////////////

        SomeType* Result_2{GetObject()};
        // Like the previous instruction, this one
        // leads to SegFault, with a log just before
        //cout << "Result: " << Result_2->Value;
    }
}