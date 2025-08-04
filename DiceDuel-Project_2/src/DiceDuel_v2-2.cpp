/*
 * File:    DiceDuel_v2-2.cpp
 * Author:  Matthew D. Anderson
 * Created: July 28th, 2025
 * Purpose: Dice Duel – v2.2 Update (Array Integration)
 *
 *          - Converted player data to 1D parallel arrays
 *          - Implemented indexed score tracking
 *          - Modular logging to gameLog.txt
 *          - Retained match flow and formatting integrity
 */

//System Libraries
#include <iostream>   //cin, cout
#include <iomanip>    //setw
#include <cstdlib>    //rand, srand
#include <ctime>      //time
#include <fstream>    //file I/O
using namespace std;

//Function Prototypes
int rollDice();
int determineRoundWinner(int, int);
void displayRoll(const string&, int);
void displayMatchSummary(const string[2], const int[2]);
void logRound(ofstream&, int, const string[2], const int[2]);

int main(int argc, char** argv){
    srand(static_cast<unsigned int>(time(0))); //Seed RNG

    //Declare Variables
    string players[2];
    int scores[2] = {0, 0};
    int rolls[2];
    int totalRounds;
    ofstream outFile;

    //Player Setup
    cout<<"=== Dice Duel v2.2 ==="<<endl;
    cout<<"Enter Player 1's name: ";
    getline(cin, players[0]);
    cout<<"Enter Player 2's name: ";
    getline(cin, players[1]);
    cout<<"Enter number of rounds to play: ";
    cin>>totalRounds;
    cin.ignore(); // clear buffer

    outFile.open("gameLog.txt");
    outFile<<"Dice Duel Game Log – v2.2"<<endl;
    outFile<<"Players: "<<players[0]<<" vs. "<<players[1]<<endl;

    //Match Loop
    for(int round = 1; round <= totalRounds; round++){
        cout<<endl<<"--- Round "<<round<<" ---"<<endl;
        rolls[0] = rollDice();
        rolls[1] = rollDice();

        for(int i = 0; i < 2; i++){
            displayRoll(players[i], rolls[i]);
        }

        int winner = determineRoundWinner(rolls[0], rolls[1]);
        if(winner == 1){
            cout<<players[0]<<" wins Round "<<round<<"!"<<endl;
            scores[0]++;
        } else if(winner == 2){
            cout<<players[1]<<" wins Round "<<round<<"!"<<endl;
            scores[1]++;
        } else {
            cout<<"Round "<<round<<" ends in a tie!"<<endl;
        }

        logRound(outFile, round, players, rolls);
    }

    //Display Final Summary
    displayMatchSummary(players, scores);

    outFile<<"Final Score: "<<players[0]<<" ("<<scores[0]<<") vs. "
           <<players[1]<<" ("<<scores[1]<<")"<<endl;
    outFile.close();

    cout<<"Thanks for playing Dice Duel v2.2!"<<endl;
    return 0;
}

//Function Definitions
int rollDice(){
    return (rand() % 6) + 1;
}

int determineRoundWinner(int r1, int r2){
    if(r1 > r2) return 1;
    else if(r2 > r1) return 2;
    else return 0;
}

void displayRoll(const string& name, int roll){
    cout<<setw(10)<<left<<name<<" rolls a "<<roll<<endl;
}

void displayMatchSummary(const string players[2], const int scores[2]){
    cout<<endl<<"=== Final Scoreboard ==="<<endl;
    for(int i = 0; i < 2; i++){
        cout<<setw(10)<<left<<players[i]<<": "<<scores[i]<<" wins"<<endl;
    }
    if(scores[0] > scores[1]) cout<<players[0]<<" takes the match!"<<endl;
    else if(scores[1] > scores[0]) cout<<players[1]<<" takes the match!"<<endl;
    else cout<<"The match ends in a draw!"<<endl;
}

void logRound(ofstream& out, int round, const string players[2], const int rolls[2]){
    out<<"Round "<<round<<": "<<players[0]<<" rolled "<<rolls[0]
       <<", "<<players[1]<<" rolled "<<rolls[1]<<endl;
}
