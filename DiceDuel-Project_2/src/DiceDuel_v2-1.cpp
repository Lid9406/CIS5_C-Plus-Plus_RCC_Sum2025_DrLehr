/*
 * File:    DiceDuel_v2-1.cpp
 * Author:  Matthew D. Anderson
 * Created: July 28th, 2025
 * Purpose: Dice Duel – v2.1 Update
 *
 *          - Modularized roll and win logic into functions
 *          - Demonstrates pass-by-value and return types
 *          - Enhanced clarity and reusability for upcoming expansions
 *          - Aligned pseudocode blocks now map 1:1 to function structure
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
int calculateWinner(int, int);
void displayRoundStats(string, string, int, int, int, int);

int main(int argc, char** argv){
    srand(static_cast<unsigned int>(time(0))); //Seed RNG

    //Declare Variables
    string player1, player2;
    int roll1, roll2, score1, score2, maxRounds;
    char again;
    ofstream outFile;

    do {
        score1 = 0;
        score2 = 0;

        cout<<"=== Dice Duel v2.1 ==="<<endl;

        //Player Names
        cout<<"Enter Player 1's name: ";
        getline(cin, player1);
        cout<<"Enter Player 2's name (or 'CPU' for solo mode): ";
        getline(cin, player2);

        //Round Setup
        cout<<"Enter number of rounds (0 for endless mode): ";
        cin>>maxRounds;
        while(cin.fail() || maxRounds < 0){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid. Enter non-negative integer: ";
            cin>>maxRounds;
        }
        cin.ignore();

        //Open Log File
        outFile.open("gameLog.txt");
        outFile<<"Dice Duel Game Log\n";
        outFile<<"Players: "<<player1<<" vs. "<<player2<<"\n";

        //Gameplay Loop
        int round = 1;
        for(; maxRounds==0 || round <= maxRounds; round++){
            roll1 = rollDice();
            roll2 = rollDice();
            score1 += roll1;
            score2 += roll2;

            displayRoundStats(player1, player2, roll1, roll2, score1, score2);
            outFile<<"Round "<<round<<": "<<player1<<" rolled "<<roll1
                   <<", "<<player2<<" rolled "<<roll2<<"\n";

            if(score1>=30 || score2>=30){
                break;
            }
        }

        //Game Summary
        cout<<"\n*** GAME OVER ***"<<endl;
        cout<<"Rounds Played: "<<round<<endl;
        cout<<player1<<" Final Score: "<<score1<<endl;
        cout<<player2<<" Final Score: "<<score2<<endl;

        int result = calculateWinner(score1, score2);
        switch(result){
            case 0: cout<<"It's a tie!"<<endl; break;
            case 1: cout<<player1<<" WINS!"<<endl; break;
            case 2: cout<<player2<<" WINS!"<<endl; break;
        }

        outFile<<"Final Score: "<<player1<<" ("<<score1<<") vs. "
               <<player2<<" ("<<score2<<")\n";
        outFile.close();

        //Replay Prompt
        cout<<"Play again? (Y/N): ";
        cin>>again;
        while(cin.fail() || (again!='Y' && again!='y' && again!='N' && again!='n')){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid input. Enter Y or N: ";
            cin>>again;
        }
        cin.ignore();

    } while(again=='Y'||again=='y');

    cout<<"Thanks for playing Dice Duel v2.1!"<<endl;
    return 0;
}

//Function Definitions
int rollDice(){
    return (rand()%6)+1;
}

int calculateWinner(int score1, int score2){
    if(score1 == score2) return 0;
    else if(score1 > score2) return 1;
    else return 2;
}

void displayRoundStats(string p1, string p2, int r1, int r2, int s1, int s2){
    static int roundNum = 1;
    cout<<"\n--- Round "<<roundNum<<" ---"<<endl;
    cout<<setw(10)<<left<<"Player"<<setw(8)<<"Roll"<<setw(10)<<"Score"<<endl;
    cout<<setw(10)<<p1<<setw(8)<<r1<<setw(10)<<s1<<endl;
    cout<<setw(10)<<p2<<setw(8)<<r2<<setw(10)<<s2<<endl;
    roundNum++;
}
