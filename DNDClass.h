#ifndef DNDCLASS_H
#define DNDCLASS_H

#include <stdbool.h>

// Define array size limits
#define MAX_ARMOR_PROF 10
#define MAX_WEAPON_PROF 15
#define MAX_SAVE_THROWS 6
#define MAX_SKILLS 18
#define MAX_EXTRA_PROF 10
#define MAX_FEATURES 20
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
    char spellcastingType[4]; // "Full", "Half", "Pact", "None"

    int profBonus;
} Class;

// Function prototypes
Class* getClassInfo(const char* className);
void displayClassInfo(Class* chosenClass);
void extraFeatureDisplay(Class* chosenClass);
char* detailedSearchClass(Class* chosenClass, const char* searchTerm);
char* detailedSearchFeature(const char* featureName);

// Load class data from a plain-text file (see example in `classes/Barbarian.txt`)
// Format: lines of "Key: value". Lists use semicolons to separate items.
// Returns 0 on success, non-zero on error.
int loadClassFromFile(const char* filepath, Class* outClass);

#endif
