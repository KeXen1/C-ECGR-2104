#ifndef SURVIVALGAME_H
#define SURVIVALGAME_H

#include <iostream>

using namespace std;

class Player {
    public:
    Player(int x, int y);
    int getScore() const;
    void takeDamage(int val);
    void takeTurn();
    string getStats() const;
    bool isAlive() const;
    void gainHealth(int val);
    void increaseThirst(int val);
    void decreaseThirst(int val);
    void increaseHunger(int val);
    void decreaseHunger(int val);
    
    int x, y;
    private:
    int health, hunger, thirst, score;
    static const int MAX_HEALTH;
    static const int MAX_HUNGER;
    static const int MAX_THIRST;
};

class Land {
    public:
    virtual string getDescription() = 0;
    virtual string visit(Player& player) = 0;
};

// TODO: Define at least 3 more types of derivded land types
// TODO: Add some unique effect to each new type

class Forest : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Lake : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Desert : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Cave : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

class Village : public Land {
    public:
    string getDescription();
    string visit(Player& player);
};

static const int MAP_SIZE = 10;
void populateMap(Land* map[][MAP_SIZE]);

#endif