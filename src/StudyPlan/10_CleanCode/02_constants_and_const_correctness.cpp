#include <iostream>
#include <memory>

using namespace std;

/////////////////////////////////////////////
//
//            const correctness
//
/////////////////////////////////////////////

class Character {
    public:
        int GetHealth() {return mHealth;}
        void SetHealth(int Health) {
            mHealth = Health;
        }

    private:
        int mHealth{100};
};

void MyFunction(Character& Input) {};

void MyFunction_2(const Character& Input) {};

// cf run()

/////////////////////////////////////////////
//
//          const member functions
//
/////////////////////////////////////////////

class Character_2 {
    public:
        int GetHealth() const { return mHealth; }
        void SetHealth(int Health) {
            mHealth = Health;
        }
    
    private:
        int mHealth{100};
};

void MyFunction_3(const Character_2& Input) {
    // Because Input is const, this can work only
    // if GetHealth() is const too
    cout << "Health: " << Input.GetHealth() << endl;
}

// cf run_2()

/////////////////////////////////////////////
//
//             const variables
//
/////////////////////////////////////////////

// cf run_3()

class Character_3 {
    public:
        int Health{100};
        const int Level{1};
};

// cf run_4()

// Passing by non-const reference
void MyFunction_4(Character_3& Input) {}

// cf run_5()

void MyFunction_5(int Number) {
    // Incrementing a copy
    Number++;
}

// cf run_6()

/////////////////////////////////////////////
//
//             const pointers
//
/////////////////////////////////////////////

// From the perspective of pointers, our use
// of const can take four different forms:

// 1 - Nothing is const

// cf run_7()

// 2 - The pointer is const

// cf run_8()

// 3 - The object being pointed at is const

// cf run_9()

// 4 - Both the pointer and the object are const

// cf run_10()

/////////////////////////////////////////////
//
//          const unique pointers
//
/////////////////////////////////////////////

// 1 - Non const pointer to non-const

// cf run_11()

// 2 - Const pointer to non-const

// cf run_12()

// 3 - Non-const pointer to const

// cf run_13()

// 4 - Const pointer to const

// cf run_14()

/////////////////////////////////////////////
//
//          const return types
//
/////////////////////////////////////////////

const int GetNumber() {
    return 1;
}

// cf run_15()

class Character_4 {};

Character_4 Player;

const Character_4& GetPlayer() {
    return Player;
}

// cf run_16()

const Character_4* GetPlayer_2() {
    return &Player;
}

// cf run_17()

/////////////////////////////////////////////
//
//   Compile time constants and constexpr
//
/////////////////////////////////////////////

const float Gravity{9.8};
// As this variable is not going to evolve,
// we should ensure that it's a compile-time constant:
constexpr float Gravity_{9.8};

/////////////////////////////////////////////
//
//       When to avoid using const
//
/////////////////////////////////////////////

// We saw it earlier, there is no reason to
// use const for a value retruned by a function:
const int Add(int x, int y) { // const here is useless
    return x + y;
}

// Here, making Damage const is not pertinent as
// it will be discarded after two lines of code
int Health{150};
bool isImmune{true};

void TakeDamage() {
    int Damage{isImmune ? 0 : 100};
    Health -= Damage;
}

/////////////////////////////////////////////
//
//      Removing const with const_cast
//
/////////////////////////////////////////////

class Character_5 {
    public:
        int GetHealth() { return mHealth; }
        void SetHealth(int Health) {
            mHealth = Health;
        }
    
    private:
        int mHealth{100};
};

// Assume we can't change the code in this
namespace SomeLibrary {
    // This function doesn't modify Input,
    // but has not marked it as const
    void LogHealth(Character_5& Input) {
        cout << "Health: " << Input.GetHealth() << endl;
    }
}

void Report(const Character_5& Input) {
    // This will not work without the const_cast
    SomeLibrary::LogHealth(const_cast<Character_5&>(Input));
}

// cf run_18()

/////////////////////////////////////////////
//
//              mutable members
//
/////////////////////////////////////////////



namespace ConstantsAndConstCorrectness {

    void run() {
        Character Player;
        MyFunction(Player);
        // What is Player's health now?
        // To make things clear, we can ensure that
        // our function will not change our variable
        MyFunction_2(Player);
    }

    void run_2() {
        Character_2 Player;
        MyFunction_3(Player);
    }

    void run_3() {
        const int Health{100};
        // This will not work as we try to modify
        // a const variable:
        //Health++;
    }

    void run_4() {
        Character_3 Player;
        // This will not work either
        //Player.Level++;

        Player.Health++; // This si OK

        const Character_3 Player_2;
        //Player_2.Health++; // This is not
    }

    void run_5() {
        Character_3 PlayerOne;
        MyFunction_4(PlayerOne); // This is fine

        const Character_3 PlayerTwo;
        //MyFunction_4(PlayerTwo); // This is not
    }

    void run_6() {
        const int Number{5};

        // Passing a const by value to a
        // non-const function parameter is fine
        MyFunction_5(Number);

        cout << "Number is still " << Number << endl;
    }

    void run_7() {
        int Number{5};
        int* Ptr{&Number};

        // We can modify the object
        (*Ptr)++;

        // We can modify the pointer
        Ptr = nullptr;
    }

    void run_8() {
        int Number{5};
        int* const Ptr{&Number};

        // We can modify the object
        (*Ptr)++;

        // We can NOT modify the pointer
        //Ptr = nullptr;
    }

    void run_9() {
        int Number{5};
        const int* Ptr{&Number};

        // We can NOT modify the object
        //(*Ptr)++;

        // We can modify the pointer
        Ptr = nullptr;
    }

    void run_10() {
        int Number{5};
        const int* const Ptr{&Number};

        // We can NOT modify the object
        //(*Ptr)++;

        // We can NOT modify the pointer
        //Ptr = nullptr;
    }

    void run_11() {
        auto Pointer{make_unique<int>(42)};

        // Modify the underlying object
        (*Pointer)++;

        // Modify the pointer
        Pointer.reset();
    }

    void run_12() {
        const auto Pointer{
            make_unique<int>(42)};
        
        // Modify the underlying object
        (*Pointer)++;

        // Error - can't modify the pointer
        //Pointer.reset();
    }

    void run_13() {
        auto Pointer{
            make_unique<const int>(42)
        };

        // Error - can't modify the underlying object
        //(*Pointer)++;

        // Modify the pointer
        Pointer.reset();
    }

    void run_14() {
        const auto Pointer{
            make_unique<const int>(42)
        };

        // Error - can't modify the underlying object
        //(*Pointer)++;

        // Error - can't modify the pointer
        //Pointer.reset();
    }

    void run_15() {
        int A{GetNumber()};
        A++; // This is fine

        const int B{GetNumber()};
        //B++; // This si not
    }

    void run_16() {
        const Character_4& PlayerPointer{GetPlayer()};
    }

    void run_17() {
        const Character_4* PlayerPointer{GetPlayer_2()};
    }

    void run_18() {
        Character_5 Player;
        Report(Player);
    }
}