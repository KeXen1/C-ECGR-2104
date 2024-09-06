#include <iostream>
#include <sstream>
#include <time.h>
#include <limits>
#include "survival_game.h"

using namespace std;

int main(){
    srand(time(0));
    
    const int MAP_SIZE = 10;
    Land* map[MAP_SIZE][MAP_SIZE];
    populateMap(map);
    
    Player player(MAP_SIZE/2, MAP_SIZE/2);
    
    cout << "You wake up and find yourself lost in the middle of a strange wilderness." << endl;
    
    // TODO: Handle boundary conditions (e.g., if index out of bounds north, you index the south-most location)
    
    while(player.isAlive()){
         
        cout << "To the north you see " << map[player.x][(((player.y - 1) % MAP_SIZE) + MAP_SIZE) % MAP_SIZE]->getDescription() << endl;
        cout << "To the east you see " << map[(player.x + 1) % MAP_SIZE][player.y]->getDescription() << endl;
        cout << "To the south you see " << map[player.x][(player.y + 1) % MAP_SIZE]->getDescription() << endl;
        cout << "To the west you see " << map[(((player.x - 1) % MAP_SIZE) + MAP_SIZE) % MAP_SIZE][player.y]->getDescription() << endl;
        
        cout << "Which way will you go? Enter N, E, S, or W:" << endl;
        char userInput;
        bool validDirectionEntered = false;
        
        while(!validDirectionEntered){
            cin >> userInput;
            try{
                switch(userInput){
                    case 'N':
                        player.y = player.y - 1;
                        if(player.y == -1){
                            player.y = ((player.y % MAP_SIZE) + 10) % MAP_SIZE;
                        }
                        validDirectionEntered = true;
                        break;
                    case 'E':
                        player.x = player.x + 1;
                        if(player.x == MAP_SIZE){
                            player.x = player.x % MAP_SIZE;
                        }
                        validDirectionEntered = true;
                        break;
                    case 'S':
                        player.y = player.y + 1;
                        if(player.y == MAP_SIZE){
                            player.y = player.y % MAP_SIZE;
                        }
                        validDirectionEntered = true;
                        break;
                    case 'W':
                        player.x = player.x - 1;
                        if(player.x == -1){
                            player.x = ((player.x % MAP_SIZE) + 10) % MAP_SIZE;
                        }
                        validDirectionEntered = true;
                        break;
                    default:
                        throw runtime_error("Invalid direction. Try again...");
                        break;
                }
                cout << map[player.x][player.y]->visit(player) << endl;
            } catch(runtime_error e){
                cout << e.what() << endl;
            }
        }
        
        player.takeTurn();
            
        cout << player.getStats() << endl;
    }
    cout << "You died." << endl;
    cout << player.getScore() << endl;
    
    return 0;
}