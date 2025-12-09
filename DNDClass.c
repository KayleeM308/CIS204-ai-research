#include "DNDClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

////Extra feature; used in loadClassFromFile extra features
//Found this
int search_in_features(char* search, char arr[][256]) {
    for (int i = 0; i < (sizeof(arr[i]) / sizeof(arr[i][256])); i++) {
        if (strcmp(search, arr[i]) == 0) {
            return i; // Found
        }
    }
    return -1; // Not found
}

////Looping print function: seperated because of repetitive code. 
// Used in displayClassInfo function
void loopingPrint(char arr[][256]) {
    int i = 0; //Initialize i
    int j = 0;
    while (arr[i][0] != '\0') { //To end early if no (more) proficiencies
        if (i != 0 && j != 5) //To ensure no comma before first
            printf(", ");
        if (j == 5) { //So display does not go off the side of the screen
            printf("\n ");
            j = 0;
        }
        printf("%s", arr[i]);
        i++; //Incrementation
        j++;
    }
}

// Function: loadClassFromFile
// Purpose: Load class data from a plain-text file into a Class struct
// Algorithm:
//   1. Open the specified file for reading
//   2. Read each line and parse key-value pairs
//   3. For list-type fields, split values by semicolons and store in arrays
//   4. Populate the provided Class struct with parsed data
//   5. Close the file and return 0 on success, non-zero on error
int loadClassFromFile(const char* filepath, Class* outClass)
{
    // Open the file
    FILE* classfile = fopen(filepath, "r");
    if (classfile == NULL) {
        return -1; // Error opening file
    }

    // Variable Declaration
    char line[512]; // Buffer for reading lines
    //char originalLine[512]; //To keep original line
    char* token; //Key token for compare
    char* temp; //Rest of line after key
    int i; //loop variable
    int featureCnt = 0;
    int extraFeatCnt = 0;
    int extraListPos = 0; //Position of extra features. Will always have Subclasses
    
    //While there are lines to read
    while ((temp = fgets(line, sizeof(line), classfile)) != NULL) { //Makes temp = line to save original line
    
        token = strtok_r(temp, ":", &temp); //Takes the first token (key)

        //Compare key and populate struct fields
        //// Name
        if (strcmp(token, "Name") == 0) {
            strcpy(outClass->name, temp);
        }
        //// Hit Die
        else if(strcmp(token, "HitDie") == 0) {
            strcpy(outClass->hitDie, temp);
        }
        //// Armor Proficiencies
        else if(strcmp(token, "ArmorProf") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->armorProf[i], profToken);
                i++;
            }
        }
        //// Weapon Proficiencies
        else if(strcmp(token, "WeaponProf") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->weaponProf[i], profToken);
                i++;
            }
        }
        //// Saving Throw Proficiencies
        else if(strcmp(token, "SavingThrows") == 0) {
            char* profToken;
            for (i = 0; i < 2; i++) {
                profToken = strtok_r(temp, ";", &temp);
                strcpy(outClass->savingThrowProf[i], profToken);
            }
        }
        //// Skill Proficiencies
        else if(strcmp(token, "Skills") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->skillProf[i], profToken);
                i++;
            }
        }
        //// Extra (Tools & Languages) Profs
        else if(strcmp(token, "ExtraProf") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->extraProf[i], profToken);
                i++;
            }
        }
        //// Features (1 - 20)
        else if(isdigit(token[0])) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->features[featureCnt][i], profToken);

                //If extra feature
                if (strchr(profToken, '*') != NULL) {
                    if (strchr(profToken, '\n') != NULL)
                        strncpy(outClass->extraFeatName[extraFeatCnt], profToken, sizeof(profToken)/sizeof(profToken[0]));
                    else
                        strcpy(outClass->extraFeatName[extraFeatCnt], profToken);
                    extraFeatCnt++;
                }

                i++;
            } 
            
            featureCnt++; //increment feature number to go through 1-20
        }
        //// Spellcasting
        else if (strcmp(token, "Spellcasting") == 0) {
            strncpy(outClass->spellcastingType, temp, 4);
        }
        ////Extra features
        //Calls search_in_features function for index, if index > 0 the coninues, if not then pass
        else {
            char* profToken;
            i = 0;

            outClass->extraFeatName[extraListPos][0] = '\0';
            strcpy(outClass->extraFeatName[extraListPos], token);

            //Going through the list of proficiencies
            
            while ((profToken = strtok_r(temp, ";", &temp)) != NULL) {
                strcpy(outClass->extraFeatList[extraListPos][i], profToken);
                i++;
            }

            extraListPos++;
            
        }
    }

    //Close file
    fclose(classfile);
return 0;
}   

// Function: getClassInfo
// Purpose: Retrieve class information based on class name
// Algorithm:
//   1. Take the className as input
//   2. Search through available classes (Barbarian, Bard, Cleric, etc.)
//   3. When matching class is found, allocate memory for a new Class struct
//   4. Populate all struct fields with the class data (name, hitDie, proficiencies, features, subclasses)
//   5. Return a pointer to the populated Class struct
//   6. If class not found, return NULL
Class* getClassInfo(char* className, Class* classList, int classCount) 
{
    // TODO: Implement class lookup and struct population



    
    return NULL;
}

// Function: displayClassInfo
// Purpose: Display class information in a formatted, easy-to-read output
// Algorithm:
//   1. Check if the pointer is valid (not NULL)
//   2. Print class name prominently
//   3. Print hit die
//   4. Print all proficiencies (armor, weapon, saving throws, skills, extra)
//   5. Print features by level (iterate through features array, skip empty entries)
//   6. Print subclasses available
//   7. Print spellcasting status (yes/no)
//   8. Call extraFeatureDisplay() if applicable
void displayClassInfo(Class* chosenClass)
{
    //Display class contents.
    printf("\n||||| CLASS OVERVIEW |||||\n\n");
    printf("%s\n", chosenClass->name); //Class name
    printf("Hit Point Die: %s", chosenClass->hitDie); //Class hit die
    printf("Saving Throws: %s and %s", chosenClass->savingThrowProf[0], chosenClass->savingThrowProf[1]); //Only ever 2

    //Looping for other proficiences
    //Armor
    printf("Armor: ");
    loopingPrint(chosenClass->armorProf);

    //Weapon
    printf("Weapon: ");
    loopingPrint(chosenClass->weaponProf);

    //Skills
    printf("Skills (Chosen from):\n ");
    loopingPrint(chosenClass->skillProf);

    //Languages and Tools
    printf("Tool and Language: ");
    loopingPrint(chosenClass->extraProf);

    //Spellcasting
    printf("Has Spellcasting?: ");
    if (strcmp(chosenClass->spellcastingType, "None") == 0) {
        printf("No");
    } else {
        printf("Yes, ");
        if (strcmp(chosenClass->spellcastingType, "Pact") == 0) {
            printf("Pact Magic");
        } else {
            printf("%s Caster", chosenClass->spellcastingType);
        }
    }

    //Features
    printf("\n\nFeatures:\n");
    for (int j = 0; j < 20; j++) {
        printf("%d: ", j + 1);
        loopingPrint(chosenClass->features[j]);
    }

    //Extra Features
    printf("\n");
    int j = 0; //Initialize i
    while (chosenClass->extraFeatName[j][0] != '\0') { //To end early if no (more) extra
        printf("%s\n ", chosenClass->extraFeatName[j]);
        loopingPrint(chosenClass->extraFeatList[j]);
        j++;
        printf("\n");
    }
    

    return;
}

// Function: extraFeatureDisplay
// Purpose: Display special class features (like Warlock invocations or Sorcerer metamagic)
// Algorithm:
//   1. Check if the class has special features to display
//   2. Determine which class it is (check name)
//   3. Display class-specific extra features/mechanics
//   4. This is a helper function called by displayClassInfo()
void extraFeatureDisplay(Class* chosenClass)
{
    // TODO: Implement display of class-specific extra features
    
    return;
}

// Function: detailedSearchClass
// Purpose: Search for specific information within a class (like "Barbarian - Proficiencies")
// Algorithm:
//   1. Take a Class pointer and a search term (like "Proficiencies", "Features", "Subclasses")
//   2. Match the search term to the appropriate struct field
//   3. Return a formatted string with the requested information
//   4. If search term not found, return an appropriate message
char* detailedSearchClass(Class* chosenClass, const char* searchTerm)
{
    // TODO: Implement detailed search within a class
    
    return NULL;
}

// Function: detailedSearchFeature
// Purpose: Search across all classes for a specific feature (like "Extra Attack")
// Algorithm:
//   1. Take a feature name as input (like "Extra Attack")
//   2. Search through all available classes
//   3. Check each class's features array for a match
//   4. Collect all class names that have this feature
//   5. Return a formatted string listing all classes with that feature
//   6. If no classes have the feature, return an appropriate message
char* detailedSearchFeature(const char* featureName)
{
    // TODO: Implement cross-class feature search
    
    return NULL;
}


