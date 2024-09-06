#include "survival_game.h"
#include <iostream>
#include <sstream>
#include <time.h>
#include <limits>

const int Player::MAX_HEALTH = 5;
const int Player::MAX_HUNGER = 5;
const int Player::MAX_THIRST = 3;
    
Player::Player(int x, int y){
    health = MAX_HEALTH;
    hunger = MAX_HUNGER;
    thirst = MAX_THIRST;
    
    this->x = x;
    this->y = y;
    this->score = 0;
}

int Player::getScore() const{
    return score;
}

void Player::takeDamage(int val){
    this->health -= val;
    if(this->health <= 0) this->health = 0;
}

void Player::takeTurn(){
    if(this->thirst <= 0){
        this->health--;
        this->thirst = 0;
    }
    
    if(this->hunger <= 0){
        this->health--;
        this->hunger = 0;
    }
    
    this->score++;
}

string Player::getStats() const{
    stringstream ss;
    ss  << "============\n"
        << "Health: " << this->health << "\n" 
        << "Hunger: " << this->hunger << "\n" 
        << "Thirst: " << this->thirst << "\n"
        << "============\n";
    return ss.str();
}

bool Player::isAlive() const {
    return this->health > 0;
}

void Player::gainHealth(int val){
    this->health += val;
    if(this->health >= MAX_HEALTH) this->health = MAX_HEALTH;
}

void Player::increaseThirst(int val){
    this->thirst = this->thirst + val;
    if(this->thirst > MAX_THIRST) this->thirst = MAX_THIRST;
}
    
void Player::decreaseThirst(int val){
    this->thirst = this->thirst - val;
    if(this->thirst <= 0) this->thirst = 0;
}

void Player::increaseHunger(int val){
    this->hunger += val;
    if(this->hunger > MAX_HUNGER) this->hunger = MAX_HUNGER;
}

void Player::decreaseHunger(int val){
    this->hunger = this->hunger - val;
    if(this->hunger <= 0) this->hunger = 0;
}

string Forest::getDescription(){
    return "a densely wooded forest.";
}

string Forest::visit(Player& player){
    int randomNum = rand() % 100;
    
    if(randomNum > 74){
        player.takeDamage(1);
        player.decreaseHunger(1);
        player.decreaseThirst(1);
        return "You are attacked by a bear while foraging for berries.";
    } else {
        player.increaseHunger(1);
        player.decreaseThirst(1);
        return "You forage for berries in the woods and eat a few.";
    }
}

string Lake::getDescription(){
    return "a clear sparkling lake.";
}

string Lake::visit(Player& player){
    player.increaseThirst(2);
    player.decreaseHunger(1);
    return "You visit the lake and drink its clean water.";
}

string Desert::getDescription(){
    return "a dry dusty desert.";
}

string Desert::visit(Player& player){
    int randNum = rand() % 100;
    if(randNum > 29){
        int randDice = (rand() % 4) + 1;
        int diceInput;
        bool validInput = false;
        cout << "You enter a pyramind. You find four treasure at the end but only have enough space to take one item." << 
        "Type 1 to 4 to pick an item." << endl;
        while(!validInput){
            cin >> diceInput;
            if(randDice == diceInput){
                player.gainHealth(5);
                player.increaseHunger(5);
                player.increaseThirst(5);
                validInput = true;
                return "You found a genie lamp! Your first wish is to escape the desert.\nYour second wish is to refill your hunger, health, and thirst.\n"
                "Your third wish was stolen by a random parrot who wished it could talk.";
            } else if(cin.fail()){
                cout << "Invalid number. Please enter a number." << endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if(diceInput > 4 || diceInput < 1){
                cout << "Invalid number. Try again..." << endl;
            } else {
                player.decreaseHunger(1);
                player.decreaseThirst(1);
                validInput = true;
                return "You picked up the treasure and triggered a booby trap. You flee empty handed.";
            }
        }
    } else {
        player.decreaseThirst(2);
        player.decreaseHunger(1);
        return "You traverse through the desert without any water.";
    }
    return "You traverse through the desert without any water.";
}

string Cave::getDescription(){
    return "a dark spooky cave.";
}

string Cave::visit(Player& player){
    int randNum = rand() % 100;
    if (randNum > 69){
        player.decreaseHunger(1);
        player.decreaseThirst(1);
        return "You got spooked by the fleeing bats. You leave empty handed.";
    } else { 
        player.increaseHunger(2);
        player.decreaseThirst(1);
        return "You enter a cave to find food! You leave feeling full.";
    }
}

string Village::getDescription(){
    return "a seemingly peaceful village.";
}

string Village::visit(Player& player){
    int randNum = rand() % 100;
    if (randNum > 49){
        player.gainHealth(1);
        player.increaseHunger(1);
        player.increaseThirst(1);
        return "You rest peacefully at the village tavern.";
    } else {
        player.decreaseHunger(1);
        player.decreaseThirst(1);
        return "You got chased out of the village by an angry mob.";
    }
}

void populateMap(Land* map[][MAP_SIZE]){
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            // TODO: Modify this code to add your new land types
            int randomNum = rand() % 5;
            switch(randomNum){
                case 0: // Forest
                    map[i][j] = new Forest;
                    break;
                case 1: // Lake
                    map[i][j] = new Lake;
                    break;
                case 2: // Desert
                    map[i][j] = new Desert;
                    break;
                case 3: // Cave
                    map[i][j] = new Cave;
                    break;
                case 4: // Village
                    map[i][j] = new Village;
                    break;
                default:
                    cout << "Invalid land type selected" << endl;
                    break;
            }
        }
    }
}