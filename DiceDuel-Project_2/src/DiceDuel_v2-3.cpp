/******************************************************************
 * PROGRAM NAME   : v2.3.cpp
 * AUTHOR         : Matthew D. Anderson
 * DATE           : July 28th, 2025
 * DESCRIPTION    : This version implements bubble sort on parallel
 *                  arrays (player names, scores, match times) to
 *                  organize data in descending score order.
 *                  Sorting maintains alignment across arrays to
 *                  ensure logical data integrity.
 *
 * CONCEPTS       : - Bubble sort logic
 *                  - Parallel array synchronization
 *                  - Modular function structure
 *                  - Formatted output via setw
 *
 * VERSION NOTES  : Sort logic added to replace static ordering.
 *                  Results validated through formatted output.
 *                  Screenshots captured and gameLog updated.
 ******************************************************************/

// ✳️ Include libraries for I/O and formatting
#include <iostream>
#include <iomanip>
using namespace std;

// 🧮 Constant defines player array size
const int NUM_PLAYERS = 5;

// 🔧 Function prototypes for modular design
void bubbleSort(int score[], string name[], int time[]);
void displaySortedData(int score[], string name[], int time[]);

int main() {
    // 🧾 Initialize parallel arrays: player names, scores, match times
    string playerName[NUM_PLAYERS] = {"Matt", "Jordan", "Alex", "Riley", "Casey"};
    int playerScore[NUM_PLAYERS] = {87, 92, 75, 98, 81};
    int matchTime[NUM_PLAYERS] = {12, 15, 9, 18, 11};

    // 🔁 Apply bubble sort across parallel arrays (by score)
    bubbleSort(playerScore, playerName, matchTime);

    // 🖨️ Output sorted arrays with aligned formatting
    displaySortedData(playerScore, playerName, matchTime);

    return 0;
}

void bubbleSort(int score[], string name[], int time[]) {
    // 🧠 Standard bubble sort loop: compares and swaps scores
    for (int i = 0; i < NUM_PLAYERS - 1; ++i) {
        for (int j = 0; j < NUM_PLAYERS - i - 1; ++j) {
            // 🔍 Compare score[j] and score[j+1] for descending order
            if (score[j] < score[j + 1]) {
                // 🔄 Swap scores and keep arrays synchronized
                swap(score[j], score[j + 1]);
                swap(name[j], name[j + 1]);
                swap(time[j], time[j + 1]);
            }
        }
    }
}

void displaySortedData(int score[], string name[], int time[]) {
    // 🧾 Header formatting with setw for alignment
    cout << setw(10) << "Name" << setw(10) << "Score" << setw(10) << "Time" << endl;

    // 🔄 Output each player's data in sorted order
    for (int i = 0; i < NUM_PLAYERS; ++i) {
        cout << setw(10) << name[i] << setw(10) << score[i] << setw(10) << time[i] << endl;
    }
}
