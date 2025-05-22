#include <iostream>
#include <memory>

using namespace std;

struct Weapon
{
    /* data */
};

void SomeFunction(Weapon W) {
    // ...
}

/////////////////////////////////////////////
//
//             Subresources
//
/////////////////////////////////////////////

struct Sword {
    string Name{"Iron Sword"};
    int Damage{42};
    float Durability{1.0};
};

struct Player {
    Player(Sword* Weapon) : mWeapon{Weapon} {}
    Sword* mWeapon{nullptr};
};

// cf run_2()

/////////////////////////////////////////////
//
//             Sharing resources
//
/////////////////////////////////////////////

// cf run_3()

/////////////////////////////////////////////
//
//          Copying unique pointers
//
/////////////////////////////////////////////

// cf run_4()

struct Sword_2 {

};
struct Player_2 {
    Player_2() : mWeapon{make_unique<Sword_2>()} {}
    unique_ptr<Sword_2> mWeapon;
};

// cf run_5()

/////////////////////////////////////////////
//
//            Copy constructors
//
/////////////////////////////////////////////

// We saw in the previous part that trying to
// create object from another one invokes
// Player::Player, which is a "copy constructor"

struct Sword_3 {
    // Default constructor
    Sword_3() = default;
    Sword_3(const Sword_3& Original) {
        cout << "Copying Sword" << endl;
    }
};

struct Player_3 {
    Player_3(Sword_3* Weapon) : mWeapon{Weapon} {}
    Player_3(const Player_3& Original)
    : mWeapon{Original.mWeapon} {
    // Also can be:
    // : Player_3{Original.mWeapon}
        cout << "Copying Player_3" << endl;
    }

    Sword_3* mWeapon{nullptr};
};

// cf run_6()

void SomeFunction(Sword_3 W) {

}

// cf run_7()

/////////////////////////////////////////////
//
//               Deep copying
//
/////////////////////////////////////////////

// To fix our root problem, we will go back
// to std::unique_ptr

struct Sword_4 {
    Sword_4() = default;
    Sword_4(const Sword_4& Original) {
        cout << "Copying Sword_4" << endl;
    }
};

struct Player_4 {
    Player_4() : mWeapon{make_unique<Sword_4>()} {}
    Player_4(const Player_4& Original)
    : mWeapon{make_unique<Sword_4>(
        *Original.mWeapon
    )} {
        cout << "Copying Player_4" << endl;
    }

    unique_ptr<Sword_4> mWeapon;
};

// cf run_8()

/////////////////////////////////////////////
//
//         Copy assignment operator
//
/////////////////////////////////////////////

// cf run_9()

struct Sword_5 {
    Sword_5() = default;
    Sword_5(const Sword_5& Original) {
        cout << "Copying Sword_5 by constructor" << endl;
    }
    Sword_5& operator=(const Sword_5& Original) {
        cout << "Copying Sword_5 by assignment" << endl;
        return *this;
    }
};

struct Player_5 {
    Player_5() : mWeapon{make_unique<Sword_5>()} {}
    Player_5(const Player_5& Original)
    : mWeapon{make_unique<Sword_5>(
        *Original.mWeapon
    )} {
        cout << "Copying Player_5" << endl;
    }

    Player_5& operator=(const Player_5& Original) {
        // If we want to copy an object to itself:
        // i.e. PlayerOne = PlayerOne;
        // then we test it and if true return directly
        if (&Original == this) {
            return *this;
        }

        *mWeapon = *Original.mWeapon;
        // Or:
        //mWeapon = make_unique<Sword_5>(*Original.mWeapon);

        return *this;
    }

    unique_ptr<Sword_5> mWeapon;
};

/////////////////////////////////////////////
//
//            Recursive copying
//
/////////////////////////////////////////////

struct Player_6 {
    Player_6() = default;
    Player_6(const Player_6& Original) {
        cout << "Copying Player_6 by constructor" << endl;
    }

    Player_6& operator=(const Player_6& Original) {
        cout << "Copying Player_6 by assignement" << endl;
        return *this;
    }
};

struct Party {
    Player_6 PlayerOne;
    // Other Players
    // ...
};

// cf run_10()

/////////////////////////////////////////////
//
//            Preventing copying
//
/////////////////////////////////////////////

struct Player_7 {
    Player_7() = default;
    Player_7(const Player_7&) = delete;
    Player& operator=(const Player_7&) = delete;
};

// cf run_11()

/////////////////////////////////////////////
//
//         Preview: std::shared_ptr
//
/////////////////////////////////////////////

struct Quest {};

struct Player_8 {
    Player_8()
    : CurrentQuest{make_shared<Quest>()} {}

    shared_ptr<Quest> CurrentQuest;
};

// cf run_12()

namespace CopyConstructorsAndOperators {

    void run() {

        Weapon SwordA;

        // Create SwordB by copyiong SwordA
        Weapon SwordB{SwordA};

        // Create the W parameter by copying SwordA
        SomeFunction(SwordA);

        // Update SwordA by copying values from SwordB
        SwordA = SwordB;
    }

    void run_2() {
        Sword Weapon;
        Player A{&Weapon};
        A.mWeapon->Durability = 0.9;

        Player B{A};
        B.mWeapon; // What is this, exactly?
    }

    void run_3() {
        Sword IronSword;
        Player PlayerOne{&IronSword};
        Player PlayerTwo{PlayerOne};

        if (PlayerOne.mWeapon == PlayerTwo.mWeapon) {
            cout << "Players sharing same weapon" << endl;
        }
    }

    void run_4() {
        auto WeaponA{make_unique<Sword>()};
        // We can't copy the pointer as it is unique:
        //unique_ptr<Sword> WeaponB{WeaponA};
    }

    void run_5() {
        Player_2 PlayerOne;
        // Can't be done because mWeapon is a unique pointer
        //Player_2 PlayerTwo{PlayerOne};
    }

    void run_6() {
        Sword_3 WeaponA;

        // Constructing new Swords by copying WeaponA
        Sword_3 WeaponB{WeaponA};
        Sword_3 WeaponC = WeaponA;

        // Passing by value is copying, too
        SomeFunction(WeaponA);
    }
    void run_7() {
        Sword_3 IronSword;
        Player_3 PlayerOne{&IronSword};
        Player_3 PlayerTwo{PlayerOne};

        if (PlayerOne.mWeapon == PlayerTwo.mWeapon) {
            cout << "Players sharing same weapon" << endl;
        }
    }

    void run_8() {
        Player_4 PlayerOne;
        Player_4 PlayerTwo{PlayerOne};

        if (PlayerOne.mWeapon != PlayerTwo.mWeapon) {
            cout << "Players are NOT sharing the same weapon" << endl;
        }
    }

    void run_9() {
        // Here we can't do that:
        //Player_4 PlayerOne;
        //Player_4 PlayerTwo;
        //PlayerTwo = PlayerOne; // -> unique_ptr can't be duplicated
        
        // Instead, we will define our "=" operator

        Player_5 PlayerOne;
        Player_5 PlayerTwo;

        PlayerTwo = PlayerOne;
    }

    void run_10() {
        Party PartyOne;
        Party PartyTwo{PartyOne};
        PartyOne = PartyTwo;
    }

    void run_11() {
        Player_7 PlayerOne;
        // This is not allowed:
        //Player_7 PlayerTwo{PlayerOne};
        Player_7 PlayerThree;
        // This is not allowed either:
        //PlayerThree = PlayerOne;
    }

    void run_12() {
        Player_8 PlayerOne;
        cout << "Quest owner count: "
        << PlayerOne.CurrentQuest.use_count() << endl;

        // Create a copy
        Player_8 PlayerTwo{PlayerOne};

        if (PlayerOne.CurrentQuest == PlayerTwo.CurrentQuest) {
            cout << "Players have the same quest" << endl;
        }
        cout << "Quest owner count: "
        << PlayerOne.CurrentQuest.use_count() << endl;
    }
}