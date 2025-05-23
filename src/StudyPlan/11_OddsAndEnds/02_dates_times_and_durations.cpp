#include <iostream>
#include <chrono>

using namespace std;

/////////////////////////////////////////////
//
//            Duration literals
//
/////////////////////////////////////////////

// cf run_2()

/////////////////////////////////////////////
//
//            Duration count()
//
/////////////////////////////////////////////

// cf run_3()

namespace DatesTimesAndDurations {
    using namespace std::chrono;

    void run() {

        duration Duration{weeks{2} + days{4}};

        // This will be true
        if (Duration > days(15)) {
            // ...
        }
    }

    void run_2() {
        duration hours{5h};
        duration minutes{5min};
        duration seconds{5s};
        duration milliseconds{5ms};
        duration microseconds{5us};
        duration nanoseconds{5ns};
    }

    void run_3() {
        duration Duration{5h};
        cout << Duration.count() << " hours" << endl;
    }
}