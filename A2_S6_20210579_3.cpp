// Version: 1.0
// FCAI � OOP Programming � 2023 - Assignment 2
// Program Name:	Printing Numbers.cpp
// Last Modification Date: 5/11/2023
// Author and ID and Group:	Mohamed Essam El-Din Hassan 20210579
// Teaching : Dr. Mohammad El-Ramly

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

// Function to clean the text by removing punctuation and non-alphanumeric characters
string cleanText(const string &text)
{
    string cleanedText;
    for (char c : text)
    {
        // Check if the character is alphanumeric, a hyphen, or a space, convert to lowercase
        if (isalnum(c) || c == '-' || isspace(c))
        {
            cleanedText += tolower(c);
        }
        else if (ispunct(c))
        {
            // Replace punctuation characters with a space
            cleanedText += ' ';
        }
    }
    return cleanedText;
}

int main()
{
    string filename;
    cout << "Enter the name of the file: ";
    cin >> filename;
    filename += ".txt";

    // Open the input file
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    // Map to store word-frequency pairs
    map<string, int> frequencyTable;

    string word;
    // Read the file word by word
    while (file >> word)
    {
        // Clean each word (remove punctuation and convert to lowercase)
        word = cleanText(word);
        // Check if the word is not empty after cleaning
        if (!word.empty())
        {
            // Increment the count of the word in the frequency table
            frequencyTable[word]++;
        }
    }

    file.close(); // Close the input file

    // Create and open the output file
    ofstream outputFile("Result.txt");
    if (!outputFile.is_open())
    {
        cerr << "Error creating output file!" << endl;
        return 1;
    }

    // Write header to the output file
    outputFile << "Word | Frequency\n";
    outputFile << "__________________\n";

    // Write word-frequency pairs to the output file
    for (const auto &pair : frequencyTable)
    {
        outputFile << pair.first << " | " << pair.second << endl;
        outputFile << "__________________\n";
    }

    outputFile.close(); // Close the output file
    cout << "Output written to Result.txt" << endl;

    return 0;
}
