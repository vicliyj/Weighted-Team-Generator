#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <iomanip>

using namespace std;

// Helper function prototypes
void printAllPlayers(); // Prints all players by level, used for debugging
int printLevelIndex(int, int, vector<string>); // Print players from vector given starting index up until ending index.


// Global vectors to hold all players by their skill levels
vector<string> advanced; // Vector of names of advanced level players
vector<string> intermediate; // Vector of names of all intermediate level players
vector<string> beginner; // Vector of names of all beginner level level players

int main () {
    int numberOfTeams = 0;
    int setsOfTeams = 0;
    bool notFinished = true;
    string player;
    int playerLevel;

    cout << "How many teams would you like to generate?: ";
    cin >> numberOfTeams;

    cout << "How many SETS of teams would you like to generate?: ";
    cin >> setsOfTeams;
    
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


    // Calculating number of players per team from each skill level
    double numOfBeginners = ceil(static_cast<double>(beginner.size()) / numberOfTeams);         // Splitting total number of beginner players by requested number of teams
    double numOfIntermediate = ceil(static_cast<double>(intermediate.size()) / numberOfTeams);  // Splitting total number of intermediate players by requested number of teams
    double numOfAdvanced = ceil(static_cast<double>(advanced.size()) / numberOfTeams);          // Splitting total number of advanced players by requested number of teams  
 
    // Calculating max number of players per team
    double totalPlayers = beginner.size() + intermediate.size() + advanced.size();  // Calculating total number of players
    int perTeam = totalPlayers / numberOfTeams;                                     // Calculating number of players PER TEAM

    int currSet = 0;
    
    while (currSet < setsOfTeams){
        cout << "----- " << currSet + 1 << " -----" << endl;
        currSet++;

        // Shuffling Players
        shuffle(beginner.begin(), beginner.end(), default_random_engine());
        shuffle(intermediate.begin(), intermediate.end(), default_random_engine());
        shuffle(advanced.begin(), advanced.end(), default_random_engine());
        
        // Variable Initializations
        int startBeginner = 0;              // Variable that holds the starting index to print from in "beginner" vector
        int startIntermediate = 0;          // Variable that holds the starting index to print from in "intermediate" vector
        int startAdvanced = 0;              // Variable that holds the starting index to print from in "advanced" vector
        int endBeginner = numOfBeginners;   // Variable that holds the ending index to print until in "beginner" vector
        int endIntermediate = 0;            // Variable that holds the ending index to print until in "intermediate" vector
        int endAdvanced = numOfAdvanced;    // Variable that holds the ending index to print until in "advanced" vector

        // Printing randonmized players
        // Autobalancing also occurs. For loop will print team members in a specific skill level order: advanced > beginner > intermediate
        // Accounts for when total number of players in skill level doesn't divide evenly by max number of players PER TEAM.
        // Algorithm will gurantee that advanced and beginners are always split evenly, filling the remaining spaces on the team
        // with intermediate level players, which also ensures that overall skill level of each team is balanced.
        // Currently DOES NOT handle when total number of players isn't evenly divisible by desired number of teams. 
        for (int i = 0; i < numberOfTeams; i++) {
            int currCount = 0;    

            cout << "   TEAM " << i + 1 << ": ";

            // Printing randomized advanced players
            currCount += printLevelIndex(startAdvanced, endAdvanced, advanced);
            startAdvanced = endAdvanced;
            endAdvanced += numOfAdvanced;

            // Printing randomized beginner players
            currCount += printLevelIndex(startBeginner, endBeginner, beginner);
            startBeginner = endBeginner;
            endBeginner += numOfBeginners;

            // Printing randomized intermediate players
            int fillTeam = perTeam - currCount;
            endIntermediate += fillTeam;
            printLevelIndex(startIntermediate, endIntermediate, intermediate);
            startIntermediate = endIntermediate;

            cout << endl;
        }
    }

    char done;
    cout << "Quit application (Y/N)?: ";
    cin >> done;

    if (done == 'Y' || done == 'y') {
        return 0;
    }
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

int printLevelIndex(int begIndex, int endIndex, vector<string> level) {
    int printCount = 0;

    for (begIndex; begIndex < endIndex; begIndex++) {
        cout << level[begIndex] << " | "; 
        
        printCount += 1;

        if (begIndex + 1 == level.size()) {
            break;            
        } 
    }

    return printCount;
}