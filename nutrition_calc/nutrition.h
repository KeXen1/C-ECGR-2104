#ifndef NUTRITION_H
#define NUTRITION_H

#include <iostream>

using namespace std;

class foodItem{
    public:
        foodItem(const string& STOP);
        foodItem(const string& FOOD_NAME, int calories, int totalFat, int totalSugars, int protein, int sodium);
        foodItem operator+(foodItem rhs);
        string getFoodName() const;
        int getCalories() const;
        int getTotalFat() const;
        int getTotalSugars() const;
        int getProtein() const;
        int getSodium() const;
    private:
        string foodName;
        int calories;
        int totalFat;
        int totalSugars;
        int protein;
        int sodium;
};

void meetDailyIntakes(int totalIntake, int recIntake, string intakeName);

void belowDailyIntakes(int totalIntake, int recIntake, string intakeName);

#endif