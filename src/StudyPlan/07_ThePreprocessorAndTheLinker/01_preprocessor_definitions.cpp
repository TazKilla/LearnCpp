#include <iostream>

using namespace std;

#define DEVELOPMENT_BUILD

/////////////////////////////////////////////
//
//         Text replacement macros
//
/////////////////////////////////////////////

#define DEFINE_INT int MyInt{4};
#define DEFINE_GREET(Greetings, Name)       \
void Greet(){                               \
    cout << Greetings << ", I am " << Name  \
    << endl << "Nice to meet you!" << endl; \
};

struct MyType {
    DEFINE_INT
    DEFINE_GREET("Hello there", "a new type")
};

DEFINE_GREET("Hi there", "a free function")

namespace PreprocessorDefinitions {

    void run() {
        cout << "Hello there!" << endl;

#ifndef RELEASE_BUILD
        cout << "This is not a release build" << endl;
#endif

#ifdef DEVELOPMENT_BUILD
        cout << "This is a developer build" << endl;
#elif DEMO_BUILD
        cout << "This is a demo build" << endl;
#elif RELEASE_BUILD
        cout << "This is a release build" << endl;
#else
        cout << "Enjoy this peace of engineering!" << endl;
#endif

        /////////////////////////////////////////

        DEFINE_INT
        cout << "MyInt: " << MyInt << endl;

        MyType MyObject;
        cout << "MyObject.MyInt: " << MyObject.MyInt << endl;

        /////////////////////////////////////////

        Greet();

        MyType MyObject_2;
        MyObject_2.Greet();
    }
}