#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// Helper function prototypes
void printAllPlayers(); // Prints all players by level
void printLevelIndex(int, int, vector<string>); // Print players from vector given starting index up until ending index.


// Global vectors to hold all players by their skill levels
vector<string> advanced; // Array of names of advanced level players
vector<string> intermediate; // Array of names of all intermediate level players
vector<string> beginner; // Array of names of all beginner level level players

int main () {
    int numberOfTeams = 0;
    bool notFinished = true;
    string player;
    int playerLevel;

    cout << "How many teams?: ";
    cin >> numberOfTeams;
    
    // While loop to input and sort players by their skill level
    while (notFinished) {
        cout << "Player name (enter 'done' if no more players): "; // Asking for name of player
        cin >> player; // Saving name of player

        if (player == "done") { // If user has entered "done", quit.
            notFinished = false;
            break;
        }

        cout << "Level of " << player << "? (1 = beginner, 2 = intermediate, 3 = advanced): "; // Asking for level of player
        cin >> playerLevel; // Saving level of player
        if (playerLevel == 1) {
            beginner.push_back(player);
        } else if (playerLevel == 2) {
            intermediate.push_back(player);
        } else if (playerLevel == 3) {
            advanced.push_back(player);
        } else {
            cout << "Level not found. Please try again." << endl;
            continue;
        }
    }

    // Shuffling Players
    random_shuffle(beginner.begin(), beginner.end());
    random_shuffle(intermediate.begin(), intermediate.end());
    random_shuffle(advanced.begin(), advanced.end());

    // Printing all players by level
    printAllPlayers();

    // Calculating number of players per team from each skill level
    double numOfBeginners = ceil(static_cast<double>(beginner.size()) / numberOfTeams); // Splitting total number of beginner players by requested number of teams
    double numOfIntermediate = ceil(static_cast<double>(intermediate.size()) / numberOfTeams); // Splitting total number of intermediate players by requested number of teams
    double numOfAdvanced = ceil(static_cast<double>(advanced.size()) / numberOfTeams); // Splitting total number of advanced players by requested number of teams

    cout << numOfBeginners << " " << numOfIntermediate << " " << numOfAdvanced << endl;
    
    int totalPlayers = beginner.size() + intermediate.size() + advanced.size();
    int perTeam = totalPlayers / numberOfTeams;
    
    int startBeginner = 0;
    int startIntermediate = 0;
    int startAdvanced = 0;
    int endBeginner = numOfBeginners;
    int endIntermediate = numOfIntermediate;
    int endAdvanced = numOfAdvanced;

    
    //Printing randonmized players
    for (int i = 0; i < numberOfTeams; i++) {
        cout << "TEAM " << i + 1 << ": ";

        // Printing randomized beginner players
        printLevelIndex(startBeginner, endBeginner, beginner);
        startBeginner = endBeginner;
        endBeginner += numOfBeginners;

        // Printing randomized intermediate players
        printLevelIndex(startIntermediate, endIntermediate, intermediate);
        startIntermediate = endIntermediate;
        endIntermediate += numOfIntermediate;

        // Printing randomized intermediate players
        printLevelIndex(startAdvanced, endAdvanced, advanced);
        startAdvanced = endAdvanced;
        endAdvanced += numOfAdvanced;

        cout << endl;
    }

    return 0;
}

void printAllPlayers() {
    cout << "BEGINNERS PLAYERS: " << endl; // Printing "beginner" vector
    for (int i = 0; i < beginner.size(); i++) {
        cout << i + 1 << ". " << beginner[i] << endl;
    }

    cout << "INTERMEDIATE PLAYERS: " << endl; // Printing "intermediate" vector
    for (int i = 0; i < intermediate.size(); i++) {
        cout << i + 1 << ". " << intermediate[i] << endl;
    }

    cout << "ADVANCED PLAYERS: " << endl; // Printing "advanced" vector
    for (int i = 0; i < advanced.size(); i++) {
        cout << i + 1 << ". " << advanced[i] << endl;
    }
}

void printLevelIndex(int begIndex, int endIndex, vector<string> level) {
    for (begIndex; begIndex < endIndex; begIndex++) {
        cout << level[begIndex] << " | "; 

        if (begIndex + 1 == level.size()) {
            break;            
        } 
    }
}