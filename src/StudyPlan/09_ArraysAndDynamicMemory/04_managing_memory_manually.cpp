#include <iostream>
#include <memory>

using namespace std;

/////////////////////////////////////////////
//
//    Using the new and delete operators
//
/////////////////////////////////////////////

struct Player {
    Player(string Name, int Level)
    : mName{Name}, mLevel{Level}{}

    string mName;
    int mLevel;
};

// cf run()

/////////////////////////////////////////////
//
//               Memory leaks
//
/////////////////////////////////////////////

// cf run_2()

/////////////////////////////////////////////
//
//  Resource Acquisition Is Initialization
//
/////////////////////////////////////////////

// RAII is a design pattern that ensure the
// lifecycle of resources is tied to the
// lifecycle of the objects that manage it.

struct Image {
    Image(int Width, int Height)
    : mWidth{Width}, mHeight{Height} {}

    int mWidth;
    int mHeight;
    //...
};

class Monster {
    public:
        Monster() : Art{new Image(256, 256)} {}

        ~Monster() {
            delete Art;
        }

        Image* Art{nullptr};
};

// With this pattern, if we delete a Monster,
// it automatically delete its own resources

class Encounter {
    public:
        Encounter()
        : A{new Monster()},
          B{new Monster()},
          C{new Monster()} {}
        
        ~Encounter() {
            // The Monster type uses RAII so they'll
            // delete their Image resources - we don't
            // need to worry about it here
            delete A;
            delete B;
            delete C;
        }

        Monster* A{nullptr};
        Monster* B{nullptr};
        Monster* C{nullptr};
};

class Dungeon {
    public:
        Dungeon()
        : A{new Encounter()},
          B{new Encounter()} {}
        
        ~Dungeon() {
            // We don't need to worry about the Monsters
            // as they're deleted by the Encouters
            delete A;
            delete B;
        }

        Encounter* A{nullptr};
        Encounter* B{nullptr};
};

/////////////////////////////////////////////
//
//  Polymorphism and virtual destructors
//
/////////////////////////////////////////////

class Character {
    public:
        virtual void Render() {}
        // This is needed to bypass the default
        // Character destructor and use our
        // subclasses destructor
        virtual ~Character() = default;
};

class Monster_2 : public Character {
    public:
        Monster_2()
        : Art{new Image{256, 256}} {
            cout << "Creating Monster_2" << endl;
        }

        ~Monster_2() {
            cout << "Deleting Monster_2" << endl;
            delete Art;
        }
    
    Image* Art{nullptr};
};

// cf run_3()

/////////////////////////////////////////////
//
//  Use after free and double free errors
//
/////////////////////////////////////////////

struct Image_2 {
    Image_2(int Width, int Height)
    : mWidth{Width}, mHeight{Height} {}

    int mWidth;
    int mHeight;
};

class Monster_3 {
    public:
        Monster_3() : Art{new Image_2(256, 256)} {}

        // Copy constructor
        Monster_3(const Monster_3& Other)
        : Art{new Image_2{
            Other.Art->mWidth, Other.Art->mHeight}} {}
        
        // Copy assignment operator
        Monster_3& operator=(const Monster_3& Other) {
            if (&Other == this) return *this;
            // Using default copy constructor
            *Art = *Other.Art;
            // Or delete existing one and
            // create a new one
            /*delete Art;
            Art = new Image_2(*Other.Art);*/
            return *this;
        }

        ~Monster_3() {
            delete Art;
        }
    
        Image_2* Art;
};

void Render(Monster_3 EnemyCopy) {
    // ...
}

// cf run_4()

/////////////////////////////////////////////
//
//             The rule of three
//
/////////////////////////////////////////////

// The previous problem is so common that
// a convention have been created: the rule of three.
//
// - the destructor
// - the copy constructor
// - the copy assignment constructor
//
// It says that if we need to implement any of these
// function, we'd typically need to implement all of them

/////////////////////////////////////////////
//
//    Interactions with smart pointers
//
/////////////////////////////////////////////

// Modern C++ try to avoid manual memory managment
// and smart pointers can help us in many cases.
// We will see how to combine smart and "raw" pointers

// Prototypes needed for late functions...
Image_2* GetArt();
void HandleArt(Image_2* Art);

// The get() method
// ----------------

class Monster_4 {
    public:
        Monster_4()
        //: Art{make_unique<Image_2>(256, 256)} {}
        // Or:
        : Art{GetArt()} {}

        Monster_4(const Monster_4& Other)
        : Art{make_unique<Image_2>(*Other.Art)} {}

        Monster_4& operator=(const Monster_4& Other) {
            if (&Other == this) return *this;
            *Art = *Other.Art;
            return *this;
        }

        // reset() method
        void UpdateArt(Image_2* NewArt) {
            Art.reset(NewArt);
        }

        // release() method
        ~Monster_4() {
            HandleArt(Art.release());
        }
    
    unique_ptr<Image_2> Art;
};

void Render_2(Image_2* Art) {
    // ...
}

// cf run_5()

// Constructor from "raw" pointer

Image_2* GetArt() {
    return new Image_2{256, 256};
}

// The reset() method
// ------------------

// It is used to tell to a smart pointer
// that it is managing another resource

// The release() method
// --------------------

void HandleArt(Image_2* Art) {
    // ...
    delete Art;
}

namespace ManagingMemoryManually {

    void run() {
        Player* PlayerOne{
            new Player("Anna", 42)
        };

        cout << "Name: " << PlayerOne->mName << endl;

        delete PlayerOne;
    }

    void run_2() {
        bool continueRunning{true};
        while (continueRunning) {
            new int(42);
            // Memory leaks here...
            // The best way to avoid it is to not use
            // new and delete, and prefer classes and
            // function that are memory-safe!
            continueRunning = false;
        }
    }

    void run_3() {
        Character* C{new Monster_2{}};

        // ...

        delete C;
    }

    void run_4() {
        Monster_3* Enemy{new Monster_3()};

        Render(*Enemy);

        // This leads to a Use After Free error:
        cout << "Art Width: " << Enemy->Art->mWidth << endl;

        // It also create a double free error, cause we
        // call delete twice, in the destructor of both
        // Enemy and EnemyCopy;

        // To avoid it we will implement the copy
        // and copy assignement constructors
    }

    void run_5() {
        Monster_4 A;
        Render_2(A.Art.get());
        A.UpdateArt(GetArt());
    }
}