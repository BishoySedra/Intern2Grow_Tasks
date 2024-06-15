#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// app to count the number of characters, words, and sentences in a text file.

int main()
{
    do
    {
        cout << "Words Counter App" << "\n";

        // first we need to read the text file
        // then we need to count the number of characters, words, and sentences in the text file
        // finally we need to display the results

        // let's start by reading the text file
        cout << "Reading the text file..." << "\n";
        string textFilePath;
        cout << "Please enter the path of the text file: ";
        cin >> textFilePath;

        ifstream inputFile;
        inputFile.open(textFilePath);
        if (!inputFile)
        {
            cout << "Error opening file" << "\n";
            continue;
        }

        string line;
        while (getline(inputFile, line))
        {
            cout << line << "\n";
        }

        inputFile.close();

        cout << "File read successfully" << "\n";
        cout << "Text in the file: \n"
             << line << "\n";

        // now let's count the number of characters, words, and sentences in the text file
        // we will use the following rules:
        // 1. characters: count all the characters in the text file
        // 2. words: count the number of spaces in the text file
        // 3. sentences: count the number of periods, question marks, and exclamation marks in the text file

        // let's start by counting the number of characters
        int characters = 0;
        for (char c : line)
        {
            if (isalpha(c))
            {
                characters++;
            }
        }

        cout << "Number of characters: " << characters << "\n";

        // now let's count the number of words
        int words = 0;
        for (char c : line)
        {
            if (isspace(c))
            {
                words++;
            }
        }

        cout << "Number of words: " << words << "\n";

        // now let's count the number of sentences

        int sentences = 0;
        for (char c : line)
        {
            if (c == '.' || c == '?' || c == '!')
            {
                sentences++;
            }
        }

        cout << "Number of sentences: " << sentences << "\n";

        bool repeat = false;
        cout << "Do you want to count the number of characters, words, and sentences in another text file? (y/n): ";
        char choice;
        cin >> choice;
        if (choice == 'y' || choice == 'Y')
        {
            repeat = true;
        }

        if (!repeat)
        {
            cout << "Exiting the app..." << "\n";
            break;
        }
    } while (true);

    return 0;
}