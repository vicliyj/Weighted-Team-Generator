#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// Global vectors to hold all players by their skill levels
vector<string> advanced{}; // Array of names of advanced level players
vector<string> intermediate{}; // Array of names of all intermediate level players
vector<string> beginner{}; // Array of names of all beginner level level players


// Helper function prototypes
void printPlayers(); // Prints all players by level

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

    // Printing all players by level
    printPlayers();

    // Shuffling Players
    // random_shuffle(beginner.begin(), beginner.end());
    // random_shuffle(intermediate.begin(), intermediate.end());
    // random_shuffle(advanced.begin(), advanced.end());

    // Calculating total number of players 
    //int totalPlayers = beginner.size() + intermediate.size() + advanced.size(); // Maybe don't need this

    // Calculating number of players per team from each skill level
    double numOfBeginners = ceil(static_cast<double>(beginner.size()) / numberOfTeams); // Splitting total number of beginner players by requested number of teams
    double numOfIntermediate = ceil(static_cast<double>(intermediate.size()) / numberOfTeams); // Splitting total number of intermediate players by requested number of teams
    double numOfAdvanced = ceil(static_cast<double>(advanced.size()) / numberOfTeams); // Splitting total number of advanced players by requested number of teams

    //Printing randonmized players
    for (int i = 0; i < numberOfTeams; i++) {
        cout << "TEAM " << i + 1 << ": "; // Printing team number

        // Printing "numOfBeginners" amount from "beginner" vector
        for (int j = 0; j < numOfBeginners; j++) {
            cout << beginner[j] << " ";
        }
        beginner.erase(beginner.begin(), beginner.begin() + numOfBeginners); // erasing those names from vector for next iteration
        
        // // Printing "numOfIntermediate" amount from "intermediate" vector
        // for (int k = 0; k < numOfIntermediate; k++) {
        //     cout << intermediate[k] << " ";
        // }
        // intermediate.erase(intermediate.begin(), intermediate.begin() + numOfIntermediate); // erasing those names from vector for next iteration
        
        // // Printing "numOfAdvanced" amount from "advanced" vector
        // for (int l = 0; l < numOfBeginners; l++) {
        //     cout << advanced[l] << " ";
        // }
        // advanced.erase(advanced.begin(), advanced.begin() + numOfAdvanced); // erasing those names from vector for next iteration
        
        cout << endl;
    }

    return 0;
}

void printPlayers() {
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