#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <conio.h>

using namespace std;

int main() {
    vector<string> questions; // Vector to store questions from file
    string line;

    // Read questions from file into vector
    ifstream questionFile("questions.txt"); 

    while (getline(questionFile, line)) {
        questions.push_back(line); // Add each line to vector
    }
    questionFile.close();

    // call before rand()
    srand(time(NULL)); 

    // Open results file for writing
    ofstream resultFile("QuizResults.txt");

    // Ask the user 3 random questions in the file for questions.txt
    cout << "\nWelcome to the Math Quiz" << "\n";
    for (int i = 0; i < 3; i++) 
    {
        // Generate a random index for selecting a question
        int randomNumber = rand() % questions.size(); 
        string question = questions[randomNumber];

        // Display the random question to the user
        cout << question << " = ";
        int userAnswer;
        cin >> userAnswer;

        // Save the question and user's answer to the file
        resultFile << question << " = " << userAnswer << "\n";
    }

    cout << "\nResults saved to QuizResults.txt!\n";
    resultFile.close();

    (void)_getch(); 
    return 0;
}
