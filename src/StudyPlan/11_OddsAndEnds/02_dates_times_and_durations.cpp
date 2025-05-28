#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;

/////////////////////////////////////////////
//
//             Chrono duration
//
/////////////////////////////////////////////

// --- Duration literals

// cf run_2()

// --- Duration count()

// cf run_3()

// --- Changing units using duration_cast()

// cf run_4()

// --- Using a duration to pause execution

// cf run_5()

/////////////////////////////////////////////
//
//              Chrono clocks
//
/////////////////////////////////////////////

// There is three different clocks that we can use:

// 1 - system_clock, simplest one, for most cases

// 2 - steady_clock, to ensure user can't exploit
// our software by changing system clock

// 3 - high_resolution_clock, for precise measurement
// in milli/micro/nano seconds

/////////////////////////////////////////////
//
//           Chrono time points
//
/////////////////////////////////////////////

// cf run_6()

/////////////////////////////////////////////
//
//           Using std::time_t
//
/////////////////////////////////////////////

// cf run_7()

/////////////////////////////////////////////
//
//       Date and time structs (tm)
//
/////////////////////////////////////////////

// cf run_8()

time_t HandleTime(tm* T) {
    return mktime(T);
}

/////////////////////////////////////////////
//
//  Using std::put_time() and format strings
//
/////////////////////////////////////////////

// cf run_9()

/////////////////////////////////////////////
//
//       Putting everything together
//
/////////////////////////////////////////////

void PrintTime(const time_t& Time) {
    tm TimeContainer;
    localtime_r(&Time, &TimeContainer);

    cout << put_time(
        &TimeContainer,
        "The current time is %T on %A"
    ) << endl;
}

// cf run_10()

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

    void run_4() {
        duration Duration{1.5h};
        duration Minutes{
            duration_cast<minutes>(Duration)
        };

        cout << Minutes.count() << " minutes" << endl;
    }

    void run_5() {
        cout << "Starting 5 sec break..." << endl;
        for (int i{5}; i > 0; --i) {
            cout << i << endl;
            this_thread::sleep_for(1s);
        }
        cout << "Done!" << endl;
    }

    void run_6() {
        time_point CurrentTime {
            system_clock::now()
        };
        time_t ttp = system_clock::to_time_t(CurrentTime);
        cout << "Now: " << ctime(&ttp);

        time_point ThreeWeeksAgo {
            system_clock::now() - weeks(3)
        };
        ttp = system_clock::to_time_t(ThreeWeeksAgo);
        cout << "Three weeks ago: " << ctime(&ttp);

        time_point StartTime{system_clock::now()};
        this_thread::sleep_for(seconds(5));
        time_point EndTime{system_clock::now()};
        // Create a duration from two time points
        duration RunningTime(EndTime - StartTime);
        cout << "Execution time in ms: "
        << duration_cast<milliseconds>(
            RunningTime).count() << endl;
        cout << "Execution time in us: "
        << duration_cast<microseconds>(
            RunningTime).count() << endl;
        cout << "Execution time in ns: "
        << duration_cast<nanoseconds>(
            RunningTime).count() << endl;
    }

    void run_7() {
        time_point StartTime{
            system_clock::now()
        };
        time_t Time{
            // Create time_t from time_point
            system_clock::to_time_t(StartTime)
            // We can do the opposite
            // (time_point from time_t) with from_time_t.
        };
        cout << Time << endl;
    }

    void run_8() {
        time_point StartTime {
            system_clock::now()
        };
        time_t TimeSinceEpoch {
            system_clock::to_time_t(StartTime)
        };

        // Get a tm from a time_t
        tm TimeContainer;
        localtime_r(&TimeSinceEpoch, &TimeContainer);

        cout << "The current time is "
            << TimeContainer.tm_hour << ":"
            << TimeContainer.tm_min << endl;
        
        // We also can get a time_t from a tm
        time_t ConvertedTime = HandleTime(&TimeContainer);
        cout << ConvertedTime << endl;
    }

    void run_9() {
        time_point StartTime {
            system_clock::now()
        };
        time_t TimeSinceEpoch {
            system_clock::to_time_t(StartTime)
        };

        tm TimeContainer;
        localtime_r(&TimeSinceEpoch, &TimeContainer);

        cout << put_time(
            &TimeContainer,
            "The current time is %T on %A"
        ) << endl;
    }

    void run_10() {
        time_point StartTime{system_clock::now()};
        PrintTime(system_clock::to_time_t(StartTime));

        this_thread::sleep_for(seconds(5));

        time_point EndTime{system_clock::now()};
        PrintTime(system_clock::to_time_t(EndTime));

        duration RunningTime{
            EndTime - StartTime
        };

        cout << "The running time was "
            << duration_cast<milliseconds>(RunningTime)
            .count()/1000.0 << " seconds" << endl;
    }
}