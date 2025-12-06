#include "DNDClass.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    // Read and parse the file line by line
    char line[512]; // Buffer for reading lines
    
    //While there are lines to read
    while (fgets(line, sizeof(line), file)) {
        
    }

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


