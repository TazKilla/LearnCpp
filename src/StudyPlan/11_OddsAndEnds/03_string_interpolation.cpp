#include <iostream>
//#include <format>
//#include <print>

using namespace std;

/////////////////////////////////////////////
//
//     An introduction to std::format()
//
/////////////////////////////////////////////

// cf run()

float CountBananas() { return 2.5; }

// cf run_2()

/////////////////////////////////////////////
//
//          C++23's std::print()
//
/////////////////////////////////////////////

// cf run_3()

/////////////////////////////////////////////
//
//   Including braces in a template string
//
/////////////////////////////////////////////

// cf run_4()

/////////////////////////////////////////////
//
//          Positional arguments
//
/////////////////////////////////////////////

// cf run_5()

/////////////////////////////////////////////
//
//         Formatting specifiers
//
/////////////////////////////////////////////

// cf run_6()

/////////////////////////////////////////////
//
//         Minimum width formatting
//
/////////////////////////////////////////////

// cf run_7()

namespace StringInterpolation {

    void run() {
        // std::format() is not available on my VM...
        /*format("I have {} apples", 5);

        string Apples{
            format("I have {} apples", 5)
        };

        cout << Apples 
            << format(" and {} bananas", 2);

        string Fruits{
            format(
                "{} apples, {} bananas and {} pears",
                5, 2, 8
            )
        };
        cout << Fruits << endl;*/
    }

    void run_2() {
        /*int Apples{5};
        string Fruit{
            format(
                "{} apples, {} bananas and {} pears",
                Apples, CountBananas(), "zero"
            )
        };
        cout << Fruit << endl;*/
    }

    void run_3() {
        // We can do the same as format() as follows
        // (still not implemented in gcc_12_2_0...):
        /*print("{} apples", 5);*/
    }

    void run_4() {
        /*string Fruit{
            format(
                "{} apples and some braces: {{ }}", 5
            )
        };

        cout << Fruit << endl;*/
    }

    void run_5() {
        /*string Name{
            format("{1}, {0}", "James", "Bond")
        };

        // Should output "Bond, James"
        cout << Name << endl;

        string Name_2{
            format("{1}, {0} {1}", "James", "Bond")
        };

        // Should output "Bond, James Bond"
        cout << Name_2 << endl;*/
    }

    void run_6() {
        /*string Number{
            format("{:+}", 10)
        };

        // Should output "+10"
        cout << Number << endl;

        string Number_2{
            format("{0:+}, {1:+}", 10, -42)
        };

        // Should output "+10, -42"
        cout << Number_2 << endl;*/
    }

    void run_7() {
        string Fruit{
            std::format("I have {:6} apples", 3)
        };

        // Should output "I have     3 apples"
        cout << Fruit << endl;

        // This can be helpfull when creating a table
        cout 
            << format(
                "{:8} | {:5} | {:6} |",
                "Item", "Sales", "Profit")
             
            << format(
                "{:8} | {:5} | {:6} |",
                "Apples", "53", "8.21")
             
            << format(
                "{:8} | {:5} | {:6} |",
                "Bananas", "194", "33.89")
             
            << format(
                "{:8} | {:5} | {:6} |",
                "Pears", "213", "106.35") << endl;
        // The output should be:
        /*  Item     | Sales | Profit |
            Apples   |    53 |   8.21 |
            Bananas  |   194 |  33.89 |
            Pears    |   213 | 106.35 |   */
    }
}