/******************************************************************
 * PROGRAM NAME   : DiceDuel_v2-4.cpp
 * AUTHOR         : Matthew D. Anderson
 * DATE           : July 30th, 2025
 * DESCRIPTION    : This version generates randomized match scores
 *                  and times for a set of players using parallel
 *                  arrays. Output displays unsorted results for
 *                  testing sort logic in the next version.
 *
 * CONCEPTS       : - RNG via rand()
 *                  - Time-based random seed
 *                  - Parallel array construction
 *                  - Formatted output using setw
 *
 * VERSION NOTES  : First implementation of randomized data. 
 *                  Sets up valid input for sorting in v2.3.cpp.
 *                  Static player names retained.
 ******************************************************************/

/// ✳️ Include libraries for I/O, formatting, and RNG
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// 🧮 Constant defines player array size
const int NUM_PLAYERS = 5;

// 🔧 Function prototypes
void generateRandomStats(int score[], int time[]);
void displayUnsortedData(string name[], int score[], int time[]);

int main() {
    // ⏱️ Seed RNG with system clock for variability
    srand(static_cast<unsigned int>(time(0)));

    // 🧾 Initialize player names
    string playerName[NUM_PLAYERS] = {"Matt", "Jordan", "Alex", "Riley", "Casey"};
    int playerScore[NUM_PLAYERS];
    int matchTime[NUM_PLAYERS];

    // 🎲 Generate random stats
    generateRandomStats(playerScore, matchTime);

    // 🖨️ Display initial unsorted stats
    displayUnsortedData(playerName, playerScore, matchTime);

    return 0;
}

void generateRandomStats(int score[], int time[]) {
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        // 🎯 Assign scores from 1 to 100
        score[i] = rand() % 100 + 1;

        // ⏳ Assign match time between 5 and 24 minutes
        time[i] = rand() % 20 + 5;
    }
}

void displayUnsortedData(string name[], int score[], int time[]) {
    // 🧾 Print headers for visual clarity
    cout << setw(10) << "Name" << setw(10) << "Score" << setw(10) << "Time" << endl;

    for (int i = 0; i < NUM_PLAYERS; ++i) {
        // 📊 Display randomly generated data
        cout << setw(10) << name[i] << setw(10) << score[i] << setw(10) << time[i] << endl;
    }
}
