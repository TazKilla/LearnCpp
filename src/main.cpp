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

//#include "StudyPlan/TypesAndVariables/hello_world.cpp"
//#include "StudyPlan/TypesAndVariables/variable_creation.cpp"
//#include "StudyPlan/TypesAndVariables/numbers.cpp"
//#include "StudyPlan/TypesAndVariables/booleans.cpp"
//#include "StudyPlan/TypesAndVariables/types_and_literals.cpp"
#include "ProgrammerEnC++Moderne/18_les_patrons_de_fonctions.cpp"

/**
 * @brief Main function, only used to call the run() function
 * from the currently included source file
 * 
 * @return int 
 */
int main(int, char**){

    //TypesAndLiterals::run();
    PatronsDeFonctions::run_1_2();
    PatronsDeFonctions::run_1_3_1();
    PatronsDeFonctions::run_1_3_2();
    
    return 0;
}
