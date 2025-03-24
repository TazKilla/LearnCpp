/**
 * @file main.cpp
 * @author Guillaume Roche (guilohm.roche@gmail.com)
 * @brief Main file used to follow Studyplan's C++ tutorial
 *        that you can find here: https://www.studyplan.dev/cpp
 *        and Programmer en C++ moderne, from Claude Delannoy, 2019
 * @version 0.1
 * @date 2025-03-12
 * 
 */

#include <iostream>

//#include "ProgrammerEnC++Moderne/18_les_patrons_de_fonctions.cpp"
//#include "StudyPlan/TypesAndVariables/00_lo_world.cpp"
//#include "StudyPlan/TypesAndVariables/01_variable_creation.cpp"
//#include "StudyPlan/TypesAndVariables/02_numbers.cpp"
//#include "StudyPlan/TypesAndVariables/03_booleans.cpp"
#include "StudyPlan/TypesAndVariables/04_types_and_literals.cpp"

/**
 * @brief Main function, only used to call the run() function
 * from the currently included source file
 * 
 * @return int 
 */
int main(int, char**){

    TypesAndLiterals::run();
    /*PatronsDeFonctions::run_1_2();
    PatronsDeFonctions::run_1_3_1();
    PatronsDeFonctions::run_1_3_2();

    PatronsDeFonctions::run_2_5();*/
    
    return 0;
}
