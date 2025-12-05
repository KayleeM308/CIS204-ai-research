#include "DNDClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function: main
// Purpose: Main program loop - handles user interaction and program flow
// Algorithm:
//   1. Display a welcome menu to the user
//   2. Prompt user for their choice (View class info, Search, Exit, etc.)
//   3. Based on user input, call appropriate functions
//   4. Display results in formatted output
//   5. Loop until user chooses to exit
int main()
{
    // TODO: Declare variables
    //   - Class pointer to hold retrieved class data
    //   - String buffer to store user input
    //   - Loop control variables
    
    // TODO: Display welcome message and program description
    
    // TODO: Create a menu loop that:
    //   1. Shows menu options to user:
    //      - "1. View D&D Class Information"
    //      - "2. Search for a Feature"
    //      - "3. Search Within a Class"
    //      - "4. Exit"
    //   2. Gets user input
    //   3. Validates input (check for valid menu choices)
    
    // TODO: Implement Case 1 - View Class Information:
    //   1. Prompt user to enter a class name
    //   2. Get input from user
    //   3. Call getClassInfo(className)
    //   4. Check if returned pointer is NULL
    //      - If NULL: display "Class not found" error message
    //      - If valid: call displayClassInfo(classPtr)
    //   5. Free allocated memory if necessary
    
    // TODO: Implement Case 2 - Search for a Feature:
    //   1. Prompt user to enter feature name (e.g., "Extra Attack")
    //   2. Get input from user
    //   3. Call detailedSearchFeature(featureName)
    //   4. Display results (which classes have this feature)
    //   5. Free allocated memory if necessary
    
    // TODO: Implement Case 3 - Search Within a Class:
    //   1. Prompt user to enter a class name
    //   2. Get input from user
    //   3. Call getClassInfo(className)
    //   4. If class found:
    //      a. Prompt user for search term (e.g., "Proficiencies", "Features", "Subclasses")
    //      b. Call detailedSearchClass(classPtr, searchTerm)
    //      c. Display results
    //   5. Free allocated memory
    
    // TODO: Implement Case 4 - Exit:
    //   1. Display goodbye message
    //   2. Clean up any remaining allocated memory
    //   3. Return 0 to end program
    
    // TODO: Handle invalid input:
    //   1. Display error message for unrecognized menu choice
    //   2. Prompt user to try again
    
    // TODO: Implement input validation:
    //   - Check for empty strings
    //   - Check for buffer overflow (limit input length)
    //   - Clean input (handle newline characters from fgets)
    
    return 0;
}
