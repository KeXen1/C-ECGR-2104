#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main(){
    
    bool playAgain = true;
    bool correctInput = false;
    char userInput;
    int money = 10;
    
    cout << "You have: $" << money << endl;
    cout << "Play? (Y/N)" << endl;
    cin >> userInput;
    
    while(!correctInput){
        if (userInput == 'Y' || userInput == 'y'){
            playAgain = true;
            correctInput = true;
        } else if (userInput == 'N' || userInput == 'n'){
            playAgain = false;
            correctInput = true;
        } else {
            cout << "Please type Y/N" << endl;
            cin >> userInput;
        }
    }
    
    while(playAgain && money > 0){
        
        money = money - 1;
        
        //random number generator for each slot
        srand(time(0));
        int slot1 = rand() % 4;
        int slot2 = rand() % 4;
        int slot3 = rand() % 4;
        
        //convert random numbers to symbols: 7,$,#,X
        if(slot1 == 0){
            cout << endl << "7";
        } else if(slot1 == 1){
            cout << endl << "$";
        } else if(slot1 == 2){
            cout << endl << "#";
        } else {
            cout << endl << "X";
        }
        
        if(slot2 == 0){
            cout << "7";
        } else if(slot2 == 1){
            cout << "$";
        } else if(slot2 == 2){
            cout << "#";
        } else {
            cout << "X";
        }
        
        if(slot3 == 0){
            cout << "7" << endl << endl;
        } else if(slot3 == 1){
            cout << "$" << endl << endl;
        } else if(slot3 == 2){
            cout << "#" << endl << endl;
        } else {
            cout << "X" << endl << endl;
        } 
        
        //Check for all matching
        if(slot1 == 0 && slot2 == 0 && slot3 == 0){
            money = money + 100;
            cout << "You won $100!" << endl;
        } else if (slot1 == 1 && slot2 == 1 && slot3 == 1){
            money = money + 50;
            cout << "You won $50!" << endl;
        } else if (slot1 == 2 && slot2 == 2 && slot3 == 2){
            money = money + 25;
            cout << "You won $25!" << endl;
        } else if (slot1 == 3 && slot2 == 3 && slot3 == 3){
            money = money + 10;
            cout << "You won $10!" << endl;
        } else{
            cout << "You won nothing... :(" << endl;
        }
        
        if(money > 0){
            cout << endl << "You have: $" << money << endl;
            cout << "Play again? (Y/N)" << endl;
            cin >> userInput;
            playAgain = (userInput == 'Y') || (userInput == 'y');
            correctInput = false;
            while(!correctInput){
                if (userInput == 'Y' || userInput == 'y'){
                    playAgain = true;
                    correctInput = true;
                } else if (userInput == 'N' || userInput == 'n'){
                    playAgain = false;
                    correctInput = true;
                } else {
                    cout << "Please type Y/N" << endl;
                    cin >> userInput;
                }
            }
        }
    }
    
    cout << endl << "You won: $" << money << "!" << endl;
    return 0;
}