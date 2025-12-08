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
    char originalLine[512]; //To keep original line
    char* token; //Key token for compare
    char* temp; //Rest of line after key
    int i; //loop variable
    int featureCnt = 0;
    int extraFeatCnt = 0;
    char* extraFeature; //String check for extra features
    int extraListPos; //Position of extra features. Will always have Subclasses
    
    //While there are lines to read
    while (fgets(line, sizeof(line), classfile) != NULL) {
        strcpy(originalLine, line); //Store original line for debugging
        token = strtok(originalLine, ":"); //Takes the first token (key)
        temp = strtok(NULL, ""); //Takes rest of the string
        temp++; //Skips the space
        line[0] = '\0';

        //Make sure no core dump
        if (temp != NULL)
            strcpy(line, temp); //line is assigned the rest of the string
        
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
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->armorProf[i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
                i++;
            }
        }
        //// Weapon Proficiencies
        else if(strcmp(token, "WeaponProf") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->weaponProf[i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
                i++;
            }
        }
        //// Saving Throw Proficiencies
        else if(strcmp(token, "SavingThrows") == 0) {
            char* profToken;
            for (i = 0; i < 2; i++) {
                profToken = strtok(line, ";");
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->savingThrowProf[i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
            }
        }
        //// Skill Proficiencies
        else if(strcmp(token, "Skills") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->skillProf[i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
                i++;
            }
        }
        //// Extra (Tools & Languages) Profs
        else if(strcmp(token, "ExtraProf") == 0) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->extraProf[i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
                i++;
            }
        }
        //// Features (1 - 20)
        else if(isdigit(token[0])) {
            char* profToken;
            temp = NULL;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space

                strcpy(outClass->features[featureCnt][i], profToken);

                //For features like Eldritch Invocations
                if (strchr(profToken, '*') != NULL)
                    strcpy(outClass->extraFeatName[extraFeatCnt++], profToken);

                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);

                i++; //increment position
            }  
            
            featureCnt++; //increment feature number to go through 1-20
        }
        //// Spellcasting
        else if (strcmp(token, "Spellcasting") == 0) {
            strcpy(outClass->spellcastingType, temp);
        }
        ////Extra features
        //Calls search_in_features function for index, if index > 0 the coninues, if not then pass
        else if ((extraListPos = search_in_features((extraFeature = strcat(token, "*")), outClass->extraFeatName)) > -1) {
            char* profToken;
            i = 0;

            //Going through the list of proficiencies
            while ((profToken = strtok(line, ";")) != NULL) {
                if (isspace(profToken[0]))
                    profToken++; //Skip leading space
                strcpy(outClass->extraFeatList[extraListPos][i], profToken);
                line[0] = '\0'; //Clear line for temp
                
                //Avoids segmentation fault
                temp = strtok(NULL, "");
                if (temp != NULL)
                    strcpy(line, temp);
                i++;
            }
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
Class* getClassInfo(const char* className) 
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
    // TODO: Implement formatted display of class information
    
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


