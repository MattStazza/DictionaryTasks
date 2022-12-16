// Assignment1_MatthewStasinowsky.cpp : This file contains the 'main' function. Program execution begins and ends there.
// CSP2104 - Assignment 1 - By Matthew Stasinowsky [10471721] 
// This program allows the user to perform tasks on a Dictionary file. 

// Included Libraries
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>

using namespace std;

// Word Struct - contains three strings which store the word's name, type and definition.
// Created 12th of March, 2022 by Matthew Stasinowsky
struct Word
{
    string type;
    string name;
    string definition;
};




// Declare the 'DisplayAllTasks' and 'EndOfTaskChoices' functions.
// These are declared before the Task functions to make sure they are recognised. The functions are defined later.
void DisplayAllTasks(vector <Word> dict);
void EndOfTaskChoices(int currentTask, vector <Word> dict);




// -- TASK FUNCTIONS -- 

// TASK 1 - Created 20th of March 2022 by Matthew Stasinowsky
// This function takes a vector (the Dictionary) and prompts the user to enter the word they'd like to find.
// It then loops through the Dictionary vector and if it finds a match it will display the word, it's type and definition.
void TaskOne(vector <Word> dict)
{
    bool wordFound = false;

    // Prompt User for the word they'd like to find.
    string wordToFind;
    cout << "TASK 1: \n" << endl;
    cout << "Please enter the word you'd like to find: " << endl;
    cin >> wordToFind;
    cout << endl;


    // Convert input to lowercase - from https://stackoverflow.com/questions/313970/how-to-convert-an-instance-of-stdstring-to-lower-case. 
    transform(wordToFind.begin(), wordToFind.end(), wordToFind.begin(),
        [](unsigned char c) { return std::tolower(c); });


    // Loop through Dictionary Vector and check if the word matches the user's input.
    for (size_t i = 0; i < dict.size(); i++) {
        if (wordToFind == dict[i].name) {

            wordFound = true;

            // Print Name
            cout << dict[i].name << " ";

            // Print Type - Displayed in the appropriate format (special case for Noun & Verb).
            if (dict[i].type == "n_and_v") {
                cout << "(n. v.) \n";
            } else {
                cout << "(" << dict[i].type << ".) \n";
            }

            // Print Definition
            cout << dict[i].definition << endl;
            cout << endl;
        }
        // If the loop reaches the end of the Dictionary without finding the word:
        else if (i == dict.size() - 1 && wordFound == false) {
            cout << "Word not found. \n";
            cout << endl;
        }
    }
    // Show Tasks/Options
    EndOfTaskChoices(1, dict);
}

// TASK 2 - Created 20th of March 2022 by Matthew Stasinowsky
// This function takes a vector (the Dictionary) and prompts the user to enter a letter and then the number of occurances of that letter.
// It then loops through the Dictionary vector, looping through each letter of every word, keeping track of the number of occurances per word.
// Finally it displays the words with the letter with the same or more occurances. 
void TaskTwo(vector <Word> dict)
{
    // Prompt User for the character and occurance amount they'd like to find.
    string charToFind;
    int charOccurrences;
    bool wordFound = false;

    cout << "TASK 2: \n" << endl;
    cout << "Please enter the character you'd like to find: " << endl;
    cin >> charToFind;
    cout << endl;

    cout << "Please enter the minimum number of occurences of that character: " << endl;
    cin >> charOccurrences;
    cout << endl;


    // Loop through each word in the Dictionary.
    for (size_t i = 0; i < dict.size(); i++) {

        // Get word name from Dictionary.
        string word = dict[i].name;

        // Counter to keep track of the number of occurnaces.
        int counter = 0;

        // Loop through letter of the word.
        for (int i = 0; i < word.length(); i++) {
           
            // Convert each letter from a char to a string and store in 'letter'.
            string letter = string(1, word[i]);

            // If the letter is the same as the charToFind, add to counter.
            if (letter == charToFind) {
                
                counter++;

                // Print all the words that include that character the given number of times or greater.
                if (counter >= charOccurrences) {
                    cout << word << endl;
                    wordFound = true;
                }
            }
        }
        // If at the end of the Dictionary and found NO words...
        if (i == dict.size() - 1 && wordFound == false) {
            cout << "No word(s) found. \n";
        }
    }

    // Show Tasks/Options
    cout << endl;
    EndOfTaskChoices(2, dict);
}

// TASK 3 - Created 20th of March 2022 by Matthew Stasinowsky
// This function takes a vector (the Dictionary) and loops through every letter of every word, checking to see if there is a 'q' without a following 'u'.
// It then displays the words it found.
void TaskThree(vector <Word> dict)
{
    cout << "TASK 3:" << endl;
    cout << "All words that contain a 'q' without a following 'u': \n" << endl;

    // Loop through each word in the Dictionary.
    for (size_t i = 0; i < dict.size(); i++) {

        // Get word from Dictionary.
        string word = dict[i].name;

        // Loop through each letter of the word.
        for (int i = 0; i < word.length(); i++) {

            // If the letter is 'q' AND the next letter isnt a 'u'.
            if (word[i] == 'q' && word[i + 1] != 'u') {
                cout << word << endl;
            }
            else {
                //cout << "Word(s) not found. \n";
            }
        }
    }

    // Show Tasks/Options
    cout << endl;
    EndOfTaskChoices(3, dict);
}

// ------- END -------




// -- VALIDATE INPUT -- 

// INTEGER - Created 26th of March by Matthew Stasinowsky
// This function asks the user to enter a NUMBER and ensures it's a valid integer between the minInt and maxInt paramters.
int ValidateInteger(int minInt, int maxInt)
{
    bool validInt = false;

    while (!validInt) { 
        int input;
        cin >> input;

        // Check if the input is between the min and max integer.
        if (input >= minInt && input <= maxInt) {
            return input;
        }
        else {
            // Clear input (to avoid infinite loop)
            // From: https://www.daniweb.com/programming/software-development/threads/487663/infinite-loop
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid Input \n";
            cout << endl;
            cout << "Enter a NUMBER between " << minInt << " - " << maxInt << ": \n";
        }
    }
}

// ------- END -------




// -- DISPLAY TASKS --

// EXIT - Created 27th of March by Matthew Stasinowsky
// This function displays a going away message and kills the program.
void Exit() {
    cout << endl;
    cout << "Closing program - Goodbye! \n";
    cout << "Developed by Matthew Stasinowsky \n";
    cout << endl;
    exit;
}

// ALL TASKS - Re-Created 26th of March by Matthew Stasinowsky
// This function takes a vector (The Dictionary) and then displays the available tasks the user can perform on that Dictionary.
// The user is then prompted to enter an integer which is validated to execute the corresponding task function.
void DisplayAllTasks(vector <Word> dict){
    cout << "-------------------------------------- \n";
    cout << endl;

    // Print out Task options.
    cout << "AVAILABLE TASKS: \n" << endl;
    cout << "1. Find a word." << endl;
    cout << "2. List all words with specific character(s)." << endl;
    cout << "3. List all words that contain a 'q' without a following 'u'." << endl;
    cout << "4. Exit. \n" << endl;

    int taskNumber;

    // Prompt user for Task choice.
    cout << "Please enter the Tasks's NUMBER you would like to perform: " << endl;
    taskNumber = ValidateInteger(1, 4);
    cout << endl;

    // If '1' execute Task 1 and end loop.
    if (taskNumber == 1) {
        TaskOne(dict);
    }
    // If '2' execute Task 2 and end loop.
    else if (taskNumber == 2) {
        TaskTwo(dict);
    }
    // If '3' execute Task 3 and end loop.
    else if (taskNumber == 3) {
        TaskThree(dict);
    }
    else if (taskNumber == 4) {
        Exit();
    }
}

// CHOICES - Created 26th of March by Matthew Stasinowsky
// Note: I know this (slightly) goes against the instructions but I feel this improves the users experience (UX).
// This function takes an int and vector (current task number and the Dictionary).
// It then asks the user to decide if they'd like to reperform the current task or view all the tasks.
void EndOfTaskChoices(int currentTask, vector <Word> dict)
{
    int choice;

    // Display choices
    cout << "-------------------------------------- \n";
    cout << endl;
    cout << "Would you like to: \n";
    cout << endl;
    cout << "1. Run the Task again." << endl;
    cout << "2. View all Tasks. \n";
    cout << "3. Exit." << endl;
    cout << endl;
    cout << "Please enter your choice as a NUMBER: \n";

    // Validate the user's input.
    choice = ValidateInteger(1, 3);

    // If '1' execute the 'currentTask'
    if (choice == 1) {
        if (currentTask == 1) {
            TaskOne(dict);
        }
        else if (currentTask == 2) {
            TaskTwo(dict);
        }
        else if (currentTask == 3) {
            TaskThree(dict);
        }
    }
    // If '2' list all Tasks. 
    else if (choice == 2) {
        DisplayAllTasks(dict);
    }
    else if (choice == 3) {
        Exit();
    }
}

// ------- END -------








// Main Program - Created 12th of March, 2022. Last edited 20th of March, 2022. By Matthew Stasinowsky
// --- READ FILE AND SORT DATA INTO A THE 'DICTIONARY' VECTOR ---
// This function reads the dictionary file and sorts the data line by line.
// The 'name', 'type' and 'definition' of each word is contained within an instance of the Word Struct.
// Then each Word Struct instance is added to the Dictionary Vector.
int main()
{
    // Create Dictionary Vector.
    vector <Word> Dictionary;


    // Get Dictionary File - setup with help from Module 3 Workshop.
    string filename = "dictionary2022_S1.txt";
    long begin, end, lineNumber;
    string data;

    cout << "Attemptying to read text file... Please wait...\n" << endl;
    ifstream file(filename);

    // Create Word Struct Instance.
    Word w;


    // Open file then sort and store data in Dictionary Vector.
    if (file.is_open())
    {
        // Counter used to match the line number with the right data type.
        // (Limitation is that this only works for this type of file (grouped in fours; type, name, definition, gap '**'))
        int counter = 1;

        // Loop through each line of the text file and sort data until it reaches the end of the file (eof).
        while (!file.eof())
        {
            // Read line
            getline(file, data);

            // Check for 'Separator line' ('**') - if it doesnt exist:
            if (data.find('**'))
            {
                // Set first line to 'Type'
                if (counter == 1) {
                    w.type = data;
                }
                // Set second line to 'Name'
                else if (counter == 2) {
                    w.name = data;
                }
                // Set third line to 'Definition'
                else if (counter == 3) {
                    w.definition = data;
                }
            }
            // If 'Separator Line' exists... 
            else
            {
                // Add word to Dictionary vector
                Dictionary.push_back(w);

                // Reset line counter
                counter = 0;
            }
            // Increase counter
            counter++;
        }
    }
    // Print if file can't be opened or found.
    else
    {
        cout << "Unable to open file.";
    }
    // ---------- END ----------


    // Display the available Tasks to the user and prompt for a choice (int).
    DisplayAllTasks(Dictionary);
}
