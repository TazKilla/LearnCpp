#include <iostream>
#include <bit>

using namespace std;

class Character
{
public:
    // This is a single-line comment
    int GetHealth() { return mHealth; }

private:
    /* This comment can span
     * multiple lines
     */
    int mHealth;
};

/////////////////////////////////////////////
//
//        Commenting for future work
//
/////////////////////////////////////////////

struct UserObj
{
    string Name;
    string Email;
    string SubscriptionDate;
    uint ID;
};

struct Event
{
    string Date;
    string Source;
    UserObj User;
    uint ID;
};

// TODO: send event data to the analytics
// service once it is ready
void TrackEvent(Event &Event) {}

/////////////////////////////////////////////
//
//     Commenting to explain complexity
//
/////////////////////////////////////////////

// There is an implementation of the Fast
// Inverse Square Root algorithm - see:
// wikipedia.org/wiki/Fast_inverse_square_root
float InvSqrt(float x)
{
    using std::bit_cast, std::uint32_t;

    const float y{bit_cast<float>(
        0x5f3759df - (bit_cast<uint32_t>(x) >> 1))};
    return y * (1.5f - (x * 0.5f * y * y));
}

/////////////////////////////////////////////
//
//       Commenting to give context
//
/////////////////////////////////////////////

void SendToAnalytics(Event &Event)
{
    // ...
}

void TrackEvent_2(Event &Event)
{
    // We redact user email addresses to
    // protect personnal data and privacy
    Event.User.Email = "";

    SendToAnalytics(Event);
}

/////////////////////////////////////////////
//
//       Comments as documentation
//
/////////////////////////////////////////////

/* Take a percentage of the character's
 * maximum health as damage. Returns
 * true if the damage was lethal.
 */
bool TakeDamage(float Percent)
{
    return true;
}

/////////////////////////////////////////////
//
//      Structured comments and Javadoc
//
/////////////////////////////////////////////

/**
 * @brief Take damage based on the character's
 * maximum health.
 * @param Percent - The percentage of the
 * character's max health to inflict as damage.
 * @return Wether or not the damage was lethal.
 */
bool TakeDamages(float Percent)
{
    return true;
}

namespace EffectiveCommentsAndJavadoc
{

    void run()
    {
        float result = InvSqrt(25);
        cout << result << endl;

        TakeDamage(18);

        TakeDamages(11);
    }
}