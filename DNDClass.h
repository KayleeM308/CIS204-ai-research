#ifndef DNDCLASS_H
#define DNDCLASS_H

#include <stdbool.h>

// Define array size limits
#define MAX_ARMOR_PROF 5
#define MAX_WEAPON_PROF 5
#define MAX_SAVE_THROWS 2
#define MAX_SKILLS 19
#define MAX_EXTRA_PROF 10
#define MAX_FEATURES 35
#define MAX_SUBCLASSES 4
#define MAX_STRING_LENGTH 256

// Struct definition for a D&D Class
typedef struct {
    char name[MAX_STRING_LENGTH];
    char hitDie[MAX_STRING_LENGTH];
    
    char armorProf[MAX_ARMOR_PROF][MAX_STRING_LENGTH];
    char weaponProf[MAX_WEAPON_PROF][MAX_STRING_LENGTH];
    char savingThrowProf[MAX_SAVE_THROWS][MAX_STRING_LENGTH];
    char skillProf[MAX_SKILLS][MAX_STRING_LENGTH];
    char extraProf[MAX_EXTRA_PROF][MAX_STRING_LENGTH];
    
    char features[MAX_FEATURES][MAX_FEATURES][MAX_STRING_LENGTH];
    char extraFeatName[MAX_FEATURES][MAX_STRING_LENGTH];
    char extraFeatList[MAX_FEATURES][MAX_FEATURES][MAX_STRING_LENGTH];
    char spellcastingType[5]; // "Full", "Half", "Pact", "None"
} Class;

// Function prototypes
Class* getClassInfo(char* className, Class* classList, int classCount);
void displayClassInfo(Class* chosenClass);
void detailedSearchClass(Class* chosenClass, int searchTerm);
bool detailedSearchFeature(char* featureName, Class* inClass);

// Load class data from a plain-text file (see example in `classes/Barbarian.txt`)
// Format: lines of "Key: value". Lists use semicolons to separate items.
// Returns 0 on success, non-zero on error.
int loadClassFromFile(const char* filepath, Class* outClass);

#endif
