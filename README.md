# CIS204-ai-research

## Program Purpose
- Extra: Understanding that the file requirements can have differing names
- 1) A user would use it to get a display of a requested DND class (free party)
- 2) Its very specific for DND but it would display the basic information about classes in DND. This would include proficiencies, features available at certain levels, hit dice, etc.
- 3) A DND information display for the classes in the game (will only include the free party ones)
- Extra: If there is time, designing a specific search. Like searching for classes with the Extra Attack feature (which should return barbarian, fighter, paladin, ranger)

## Input/Output/management
- 1) Users need only input a class name. A lot of the program is prebuilt.
- 2) A display of the requested DND class in a easy to read format.
- 3) A struct for the DND class, input var for the class requested.
- Extra: Could be more, I am not yet sure how many variables this will require
- 4) I am unsure how much memory it will take. I assume it may end up in KiloBytes?

## Functions (These are subject to change, simply being examples)
- 1) Class getClassInfo() //with Class being a struct, may include the search
- 2) void displayClassInfo(Class chosenClass)
- 3) void extraFeatureDisplay(Class chosenClass) Intended to be called in displayClassInfo for classes with extra features like warlock with eldritch invocation options or sorcerer with metamagic options.
- 4) #Extra# String? detailedSearchClass() //Meant to prompt for a specific search. Like Warlock - Proficiecies should return proficiencies 
- 5) #Extra# String? detailedSearchFeature() //Meant to prompt for specific search of feature. Extra Attack should return Barbarian, Fighter, Monk, Paladin, Ranger (this is from the top of my head)

## Data Structures
- Struct Class
- Example Var: name, hitDie, savingThrows, skills, extraProf, features[1-20], multiClass, spellCasting, extraFeatures

## Files
- main.c //The main program used to call functions keep the main program. Is what gets user inputs
- Helper.h (Would call it DNDClass.h) //defines the DND Class struct
- Helper.c (Would call it DNDClass.c) //Uses the struct and holds the DNDClass functions

## Research Plan
- To preface, I am not fond of AI despite using it before since it is often used malitiously

If using AI then I would like to limit my AI help to figuring out any road blocks I come across. A way to think around an issue because I would rather not use AI to build code. Some prompts that could help with figuring out some of the functions. My most immediate issue that I would have to figure out with this problem is organizing the structs variables. It may help keep track of the variables.

Prompt1: "Can you help me sort my variables and what variables fall under other ones?" This stems from the though I may need to do arrays of arrays so having a document or organization method that keeps track of my variables. So I know the steps I have to take to get the information I need.

Prompt2: "What information is important to dnd classes, listed." This is to get myself a list to pick out the variables I need for the Struct. It would make it easier to organize what I need. This is becasue dnd classes have lots of parts.

Prompt3: I do not have a specific prompt for this but prompts that are meant to help with a roadblock. Like if code is not functioning as intended then requesting help or another suggestion as to go about the problem differently.

I cannot think of anything else because I have not used AI that much. I will not say I have never used AI because it makes it easy to collect URLs for papers. Or help design features for Dungeons and Dragons games because I do a lot of homebrew. However, that leads into a discussion on if AI is good or not.