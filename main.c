#include "DNDClass.h"
#include "DNDClass.c"
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
    //Variable Declelartion
    int numClass = 12; //Number of classes
    char filepath[50];
    Class classList[12]; //Array to hold all classes
    char matchesList[12][20];
    bool programRun = true;
    int optionChoice;
    char wordChoice[30];
    Class* matchClass;
    char* cacheClear;

    char classFiles[12][50] = { //Array of class files
        "classes/Barbarian.txt", "classes/Bard.txt", "classes/Cleric.txt", "classes/Druid.txt", 
        "classes/Fighter.txt", "classes/Monk.txt", "classes/Paladin.txt", "classes/Ranger.txt", 
        "classes/Rogue.txt", "classes/Sorcerer.txt", "classes/Warlock.txt", "classes/Wizard.txt"
    };

    //Load each class from the files
    for (int i = 0; i < numClass; i++) {
        strcpy(filepath, classFiles[i]); //Copy class file to filepath

        memset(&classList[i], 0, sizeof(classList[i])); //Zero struct

        loadClassFromFile(filepath, &classList[i]); //load the class

        filepath[0] = '\0'; //Clear filepath
    }

    printf("\n\t\t|||| DND CLASS SEARCH||||\n\n"); //Welcome message
    
    while (programRun) {
        printf("||||Options||||\n\n");
        printf("1. View D&D Class Information\n");
        printf("2. Search for a Feature\n");
        printf("3. Search Within a Class\n");
        printf("4. Exit\n\n");

        printf("Option choice (Enter an integer): ");
        scanf("%d", &optionChoice);
        printf("\n");

        switch (optionChoice) {
            case 1: //View all class information
                //Get input
                printf("Enter the class you want displayed: ");
                scanf("%s", wordChoice);
                //Get matching class and display
                matchClass = getClassInfo(wordChoice, classList, numClass);
                displayClassInfo(matchClass);

                break;
            case 2: //Find classes with feature
                //Get input
                printf("Enter the information you want to check for (Ex: d8 Ex: Extra Attack): ");
                scanf("%s", wordChoice);
                //Find matching classes
                int j = 0;
                for (int i = 0; i < numClass; i++) {
                    if (detailedSearchFeature(wordChoice, &classList[i])) {
                        strcat(matchesList[j], classList[i].name);
                        j++;
                    }
                }
                //Print matching classes
                printf("\nClasses with \"%s\":", wordChoice);

                j = 0;
                for (int i = 0; i < numClass; i++) { //Prints matches
                    if (matchesList[i][0] != '\0') {
                        if (j != 0)
                            printf(",");
                        printf(" %s", matchesList[i]);
                        j++;
                    }
                }

                //If there were no matches
                if (j == 0)
                    printf(" None");

                //Clear matchesList for next time
                memset(matchesList, 0, sizeof(matchesList));
                printf("\n");

                break;
            case 3:
                //Get input
                printf("Enter the class you want to search in: ");
                scanf("%s", wordChoice);
                //Get matching class and display
                matchClass = getClassInfo(wordChoice, classList, numClass);

                if (matchClass != NULL) { //Valid input check
                    //Printing option menu
                    printf("\n|||Class Information|||\n");
                    printf("1. Hit Die\n");
                    printf("2. Saving Throws\n");
                    printf("3. Armor\n");
                    printf("4. Weapons\n");
                    printf("5. Skills\n");
                    printf("6. Extra Proficiences\n");
                    printf("7. Spellcasting\n");
                    printf("8. Features\n");
                    printf("9. Extra Features\n");
                
                    printf("Option choice (Enter an integer): ");
                    scanf("%d", &optionChoice);

                    detailedSearchClass(matchClass, optionChoice);
                } else {
                    printf("Invalid Class\n");
                }
                break;
            case 4:
                printf("Ending search......");
                programRun = false;
                break;
            default:
                printf("Invalid menu choice.\n");
                printf("Safety precaution: Ending program");
                programRun = false;
                break;
        }

        optionChoice = 0;
        printf("\n");
    }

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
