/*
 * File:    DiceDuel_v2-0.cpp
 * Author:  Matthew D. Anderson
 * Created: July 28th, 2025
 * Purpose: Dice Duel – Version 2.0 Upgrade
 *
 *          Retrofitted for Project 2 launch with the following:
 *          - Eliminated all user-defined functions
 *          - Added for-loop for round iterations
 *          - Implemented switch statement for win logic
 *          - Introduced ternary operator
 *          - Included input/output file handling
 *          - Increased code lines with inline logic and commentary
 */

//System Libraries
#include <iostream>   //cin, cout
#include <iomanip>    //setw
#include <cstdlib>    //rand, srand
#include <ctime>      //time
#include <fstream>    //file I/O
using namespace std;

int main(int argc, char** argv){
    //Random seed
    srand(static_cast<unsigned int>(time(0)));

    //Variable declarations
    string player1, player2;
    int roll1, roll2, score1, score2, maxRounds, round;
    char again;
    ofstream outFile;

    //Game loop
    do {
        score1 = 0;
        score2 = 0;
        round = 0;

        cout<<"=== Dice Duel v2.0 ==="<<endl;

        //Names
        cout<<"Enter Player 1's name: ";
        getline(cin, player1);
        cout<<"Enter Player 2's name (or 'CPU' for solo mode): ";
        getline(cin, player2);

        //Rounds
        cout<<"Enter number of rounds (0 for endless mode): ";
        cin>>maxRounds;
        while(cin.fail() || maxRounds < 0){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid. Enter a non-negative integer: ";
            cin>>maxRounds;
        }
        cin.ignore(); //Clear input buffer

        //Open file
        outFile.open("gameLog.txt");
        outFile<<"Dice Duel Game Log\n";
        outFile<<"Players: "<<player1<<" vs. "<<player2<<"\n";

        //Round loop
        for(; maxRounds==0 || round < maxRounds; round++){
            roll1 = (rand()%6)+1;
            roll2 = (rand()%6)+1;

            score1 += roll1;
            score2 += roll2;

            cout<<"\n--- Round "<<(round+1)<<" ---"<<endl;
            cout<<setw(10)<<left<<"Player"<<setw(8)<<"Roll"<<setw(10)<<"Score"<<endl;
            cout<<setw(10)<<player1<<setw(8)<<roll1<<setw(10)<<score1<<endl;
            cout<<setw(10)<<player2<<setw(8)<<roll2<<setw(10)<<score2<<endl;

            outFile<<"Round "<<(round+1)<<": "<<player1<<" rolled "<<roll1<<", "<<player2<<" rolled "<<roll2<<"\n";

            if(score1>=30 || score2>=30){
                break; //Game ends if either hits win score
            }
        }

        //Summary
        cout<<"\n*** GAME OVER ***"<<endl;
        cout<<"Rounds Played: "<<(round+1)<<endl;
        cout<<player1<<" Final Score: "<<score1<<endl;
        cout<<player2<<" Final Score: "<<score2<<endl;

        //Ternary + switch combo
        int result = (score1==score2) ? 0 : (score1>score2 ? 1 : 2);
        switch(result){
            case 0: cout<<"It's a tie!"<<endl; break;
            case 1: cout<<player1<<" WINS!"<<endl; break;
            case 2: cout<<player2<<" WINS!"<<endl; break;
        }

        outFile<<"Final Score: "<<player1<<" ("<<score1<<") vs. "<<player2<<" ("<<score2<<")\n";
        outFile.close(); //Done logging

        //Replay
        cout<<"Play again? (Y/N): ";
        cin>>again;
        while(cin.fail() || (again!='Y' && again!='y' && again!='N' && again!='n')){
            cin.clear();
            cin.ignore(1000,'\n');
            cout<<"Invalid input. Enter Y or N: ";
            cin>>again;
        }
        cin.ignore(); //Buffer flush

    } while(again=='Y'||again=='y');

    cout<<"Thanks for playing Dice Duel v2.0!"<<endl;
    return 0;
}
