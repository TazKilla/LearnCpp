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

//#include "StudyPlan/01_TypesAndVariables/00_lo_world.cpp"
//#include "StudyPlan/01_TypesAndVariables/01_variable_creation.cpp"
//#include "StudyPlan/01_TypesAndVariables/02_numbers.cpp"
//#include "StudyPlan/01_TypesAndVariables/03_booleans.cpp"
//#include "StudyPlan/01_TypesAndVariables/04_types_and_literals.cpp"

//#include "StudyPlan/02_FunctionsConditionalsAndLoops/01_create_and_call_functions.cpp"
//#include "StudyPlan/02_FunctionsConditionalsAndLoops/02_call_stack_and_debugging_functions.cpp"
//#include "StudyPlan/02_FunctionsConditionalsAndLoops/07_arguments.cpp"
//#include "StudyPlan/02_FunctionsConditionalsAndLoops/05_fizz_buzz.cpp"

//#include "StudyPlan/03_ClassesAndStructs/01_abstraction_and_classes.cpp"
//#include "StudyPlan/03_ClassesAndStructs/02_encapsulation_and_specifiers.cpp"
//#include "StudyPlan/03_ClassesAndStructs/03_constructors_and_destructors.cpp"
//#include "StudyPlan/03_ClassesAndStructs/04_structs_and_aggregate_initialization.cpp"
//#include "StudyPlan/03_ClassesAndStructs/05_operator_overloading.cpp"
//#include "StudyPlan/03_ClassesAndStructs/06_structured_binding.cpp"

//#include "StudyPlan/04_Inheritance/01_inheritance.cpp"
//#include "StudyPlan/04_Inheritance/02_protected_class_members.cpp"
//#include "StudyPlan/04_Inheritance/03_member_initializer_lists.cpp"
//#include "StudyPlan/04_Inheritance/04_working_with_inherited_memebers.cpp"

//#include "StudyPlan/05_MemoryReferencesAndPointers/01_references.cpp"
//#include "StudyPlan/05_MemoryReferencesAndPointers/02_pointers.cpp"
//#include "StudyPlan/05_MemoryReferencesAndPointers/03_the_this_pointer.cpp"
//#include "StudyPlan/05_MemoryReferencesAndPointers/04_dangling_pointers_and_references.cpp"

//#include "StudyPlan/06_Polymorphism/01_function_overloading.cpp"
//#include "StudyPlan/06_Polymorphism/02_static_casting.cpp"
//#include "StudyPlan/06_Polymorphism/03_virtual_functions_and_overrides.cpp"
//#include "StudyPlan/06_Polymorphism/04_downcasting.cpp"

//#include "StudyPlan/07_ThePreprocessorAndTheLinker/01_preprocessor_definitions.cpp"
//#include "StudyPlan/07_ThePreprocessorAndTheLinker/02_the_#include_directive.cpp"

//#include "StudyPlan/08_NamespacesAndEnums/01_namespaces.cpp"
//#include "StudyPlan/08_NamespacesAndEnums/02_enums.cpp"

//#include "StudyPlan/09_ArraysAndDynamicMemory/01_dynamic_arrays_using_std_vector.cpp"
//#include "StudyPlan/09_ArraysAndDynamicMemory/02_memory_ownership_and_smart_pointers.cpp"
//#include "StudyPlan/09_ArraysAndDynamicMemory/03_copy_constructors_and_operators.cpp"
//#include "StudyPlan/09_ArraysAndDynamicMemory/04_managing_memory_manually.cpp"

//#include "StudyPlan/10_CleanCode/01_automatic_type_detection_using_auto.cpp"
//#include "StudyPlan/10_CleanCode/02_constants_and_const_correctness.cpp"
//#include "StudyPlan/10_CleanCode/03_effective_comments_and_javadoc.cpp"

//#include "StudyPlan/11_OddsAndEnds/01_random_number_generation.cpp"
#include "StudyPlan/11_OddsAndEnds/02_dates_times_and_durations.cpp"

/**
 * @brief Main function, only used to call the run() function
 * from the currently included source file
 * 
 * @return int 
 */
int main(int, char**){

    ///////////////////////////////////////////////////////
    //
    //                    STUDY PLAN
    //
    ///////////////////////////////////////////////////////

    //TypesAndLiterals::run();

    //CreateAndCallFunctions::run();
    //CallStackAndDebuggingFunctions::run();
    //FunctionArgumentsAndParameters::run();
    //FizzBuzz();

    //AbstractionAndClasses::run();
    //EncapsulationAndSpecifiers::run();
    //ConstructorsAndDestructors::run();
    //StructsAndAggregateInitialization::run();
    //OperatorOverloading::run();
    //StructuredBinding::run();

    //Inheritance::run();
    //ProtectedClassMembers::run();
    //MemberInitializerLists::run();
    //WorkingWithInheritedMembers::run();

    //References::run();
    //Pointers::run();
    //TheThisPointer::run();
    //DanglingPointersAndReferences::run();

    //FunctionOverloading::run();
    //StaticCasting::run();
    //VirtualFunctionsAndOverrides::run();
    //Downcasting::run();

    //PreprocessorDefinitions::run();
    //TheIncludeDirective::run();

    //Namespaces::run();
    //Enums::run();

    /*DynamicArraysUsingStdVectors::run();
    DynamicArraysUsingStdVectors::run_2();
    DynamicArraysUsingStdVectors::run_3();
    DynamicArraysUsingStdVectors::run_4();
    DynamicArraysUsingStdVectors::run_5();
    DynamicArraysUsingStdVectors::run_6();
    DynamicArraysUsingStdVectors::run_7();
    DynamicArraysUsingStdVectors::run_8();
    DynamicArraysUsingStdVectors::run_9();
    DynamicArraysUsingStdVectors::run_10();
    DynamicArraysUsingStdVectors::run_11();
    DynamicArraysUsingStdVectors::run_12();
    DynamicArraysUsingStdVectors::run_13();
    MemoryOwnershipAndSmartPointers::run();
    MemoryOwnershipAndSmartPointers::run_2();
    MemoryOwnershipAndSmartPointers::run_3();
    MemoryOwnershipAndSmartPointers::run_4();
    CopyConstructorsAndOperators::run();
    CopyConstructorsAndOperators::run_2();
    CopyConstructorsAndOperators::run_3();
    CopyConstructorsAndOperators::run_4();
    CopyConstructorsAndOperators::run_5();
    CopyConstructorsAndOperators::run_6();
    CopyConstructorsAndOperators::run_7();
    CopyConstructorsAndOperators::run_8();
    CopyConstructorsAndOperators::run_9();
    CopyConstructorsAndOperators::run_10();
    CopyConstructorsAndOperators::run_11();
    CopyConstructorsAndOperators::run_12();
    ManagingMemoryManually::run();
    ManagingMemoryManually::run_2();
    ManagingMemoryManually::run_3();
    ManagingMemoryManually::run_4()*/

    /*AutomaticTypeDetectionUsingAuto::run();
    ConstantsAndConstCorrectness::run();
    ConstantsAndConstCorrectness::run_2();
    ConstantsAndConstCorrectness::run_3();
    ConstantsAndConstCorrectness::run_4();
    ConstantsAndConstCorrectness::run_5();
    ConstantsAndConstCorrectness::run_6();
    ConstantsAndConstCorrectness::run_7();
    ConstantsAndConstCorrectness::run_8();
    ConstantsAndConstCorrectness::run_9();
    ConstantsAndConstCorrectness::run_10();
    ConstantsAndConstCorrectness::run_11();
    ConstantsAndConstCorrectness::run_12();
    ConstantsAndConstCorrectness::run_13();
    ConstantsAndConstCorrectness::run_14();
    ConstantsAndConstCorrectness::run_15();
    ConstantsAndConstCorrectness::run_16();
    ConstantsAndConstCorrectness::run_17();
    ConstantsAndConstCorrectness::run_18();
    EffectiveCommentsAndJavadoc::run();*/

    /*RandomNumberGeneration::run();
    RandomNumberGeneration::run_2();
    RandomNumberGeneration::run_3();*/
    DatesTimesAndDurations::run();
    DatesTimesAndDurations::run_2();
    DatesTimesAndDurations::run_3();

    ///////////////////////////////////////////////////////
    //
    //           Programmer en C++ Moderne
    //
    ///////////////////////////////////////////////////////

    /*PatronsDeFonctions::run_1_2();
    PatronsDeFonctions::run_1_3_1();
    PatronsDeFonctions::run_1_3_2();

    PatronsDeFonctions::run_2_5();*/
    
    return 0;
}
